#include "ServerNetwork.h"





ServerNetwork::ServerNetwork()
{
	m_logger = std::make_unique<Logger>(std::cout);
	WSADATA wsaData;


	listenSocket = INVALID_SOCKET;
	clientSocket = INVALID_SOCKET;


	struct addrinfo *results = nullptr;
	struct addrinfo hints;

	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		m_logger->log("WSAStartup failed with error : " + iResult, Logger::Level::Error);
		exit((int)Logger::Level::Error);
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	iResult = getaddrinfo(nullptr, defaultServerPort, &hints, &results);

	if (iResult != 0)
	{
		m_logger->log("getaddrinfo failed with error: " + iResult, Logger::Level::Error);
		WSACleanup;
		exit((int)Logger::Level::Error);

	}

	listenSocket = socket(results->ai_family, results->ai_socktype, results->ai_protocol);

	if (listenSocket == INVALID_SOCKET)
	{
		m_logger->log("socket failed with error: " + WSAGetLastError(), Logger::Level::Error);
		freeaddrinfo(results);
		WSACleanup();
		exit((int)Logger::Level::Error);
	}

	u_long iMode = 1;
	iResult = ioctlsocket(listenSocket, FIONBIO, &iMode);


	if (iResult == SOCKET_ERROR)
	{
		m_logger->log("ioctlsocket failed with error:  " + WSAGetLastError(), Logger::Level::Error);
		closesocket(listenSocket);
		WSACleanup();
		exit((int)Logger::Level::Error);
	}

	iResult = bind(listenSocket, results->ai_addr, (int)results->ai_addrlen);

	if (iResult == SOCKET_ERROR)
	{
		m_logger->log("bind failed with error: " + WSAGetLastError(), Logger::Level::Error);
		freeaddrinfo(results);
		closesocket(listenSocket);
		WSACleanup();
		exit((int)Logger::Level::Error);
	}

	freeaddrinfo(results);

	iResult = listen(listenSocket, SOMAXCONN);

	if (iResult == SOCKET_ERROR)
	{
		m_logger->log("listen failed with error: " + WSAGetLastError(), Logger::Level::Error);
		closesocket(listenSocket);
		WSACleanup();
		exit((int)Logger::Level::Error);
	}
}


ServerNetwork::~ServerNetwork()
{
}

bool ServerNetwork::acceptNewClient(unsigned int & id)
{
	clientSocket = accept(listenSocket, nullptr, nullptr);

	if (clientSocket != INVALID_SOCKET)
	{
		//disable nagle on the client's socket
		char value = 1;
		setsockopt(clientSocket, IPPROTO_TCP, TCP_NODELAY, &value, sizeof(value));

		// insert new client into session id table
		sessions.insert(std::pair<unsigned int, SOCKET>(id, clientSocket));

		return true;
	}
	return false;
}

int ServerNetwork::receiveData(unsigned int clientId, char * receiveBuffer)
{
	if (sessions.find(clientId) != sessions.end())
	{
		SOCKET currentSocket = sessions[clientId];
		iResult = NetworkServices::receiveMessage(currentSocket, receiveBuffer, maxPacketSize );
		if (iResult == 0)
		{

			m_logger->log("Connection closed ", Logger::Level::Warning);

			closesocket(currentSocket);

		}
		return iResult;
	}
	return 0;
}

void ServerNetwork::sendToAll(char * packets, int totalSize)
{
	SOCKET currentSocket;
	std::map<unsigned int, SOCKET>::iterator iterator;

	int iSendResult;

	for (iterator = sessions.begin(); iterator != sessions.end(); iterator++)
	{
		currentSocket = iterator->second;
		iSendResult = NetworkServices::sendMessage(currentSocket, packets, totalSize);

		if (iSendResult == SOCKET_ERROR)
		{
			m_logger->log("send failed with error : " + std::to_string(WSAGetLastError()), Logger::Level::Error);
			closesocket(currentSocket);
		}
	}
}

void ServerNetwork::sendToClient(char * packets, int totalSize, int clientId)
{
	SOCKET currentSocket;
	std::map<unsigned int, SOCKET>::iterator iterator;

	int iSendResult;

	for (iterator = sessions.begin(); iterator != sessions.end(); iterator++)
	{
		if (clientId-1 == iterator->first)
		{
			currentSocket = iterator->second;
		}
	}

	iSendResult = NetworkServices::sendMessage(currentSocket, packets, totalSize);
	if (iSendResult == SOCKET_ERROR)
	{
		m_logger->log("send failed with error : " + std::to_string(WSAGetLastError()), Logger::Level::Error);
		closesocket(sessions[clientId]);
	}
}
