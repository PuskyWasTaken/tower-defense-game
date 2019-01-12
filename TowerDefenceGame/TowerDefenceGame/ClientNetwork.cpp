#include "ClientNetwork.h"
#include "ClientNetwork.h"


ClientNetwork::ClientNetwork(const char* connectionIp)
{
	init(connectionIp);
}
ClientNetwork::ClientNetwork()
{
	init("127.0.0.1");
}

ClientNetwork::~ClientNetwork()
{
}

int ClientNetwork::receivePackets(char *recvbuf)
{
	iResult = NetworkServices::receiveMessage(ConnectSocket, recvbuf, MAX_PACKET_SIZE);

	if (iResult == 0)
	{
		printf("Connection closed\n");
		closesocket(ConnectSocket);
		WSACleanup();
		exit(1);
	}

	return iResult;
}


void ClientNetwork::init(const char * connectionIp)
{
	/* Create Logger */
	m_log = std::make_unique<Logger>(std::cout);

	/* Create WSADATA object */
	WSADATA wsaData;

	/* Socket */
	ConnectSocket = INVALID_SOCKET;

	/* Holds address info for socket to connect to */
	struct addrinfo *result = nullptr,
		*ptr = nullptr,
		hints;

	/* Initialize Winsock */
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (iResult != 0) {
		m_log->log("WSAStartup failed with error: "  + std::to_string(iResult) , Logger::Level::Error);
		exit((int)Logger::Level::Error);
	}


	/* Set address info */
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;  //TCP connection!!!

	/* Resolve server address and port */
	iResult = getaddrinfo(connectionIp, DEFAULT_PORT, &hints, &result);

	if (iResult != 0)
	{
		m_log->log("getaddrinfo failed with error:  " + std::to_string(iResult), Logger::Level::Error);
		WSACleanup();
		exit((int)Logger::Level::Error);
	}

	/* Attempt to connect to an address until one succeeds */
	for (ptr = result; ptr != nullptr; ptr = ptr->ai_next) {

		/* Create a SOCKET for connecting to server */
		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
			ptr->ai_protocol);

		if (ConnectSocket == INVALID_SOCKET) {
			m_log->log("socket failed with error : " + WSAGetLastError(), Logger::Level::Error);
			WSACleanup();
			exit((int)Logger::Level::Error);
		}

		/* Connect to server */
		iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);

		if (iResult == SOCKET_ERROR)
		{
			closesocket(ConnectSocket);
			ConnectSocket = INVALID_SOCKET;
			m_log->log("The server is down... did not connect", Logger::Level::Warning);
		}
	}

	/* No longer need address info for server */
	freeaddrinfo(result);

	/* If connection failed */
	if (ConnectSocket == INVALID_SOCKET)
	{
		m_log->log("Unable to connect to server!", Logger::Level::Error);
		WSACleanup();
		exit((int)Logger::Level::Error);
	}

	/* Set the mode of the socket to be nonblocking */
	u_long iMode = 1;

	iResult = ioctlsocket(ConnectSocket, FIONBIO, &iMode);
	if (iResult == SOCKET_ERROR)
	{
		m_log->log("ioctlsocket failed with error: " + WSAGetLastError(), Logger::Level::Error);
		closesocket(ConnectSocket);
		WSACleanup();
		exit((int)Logger::Level::Error);
	}

	/* Disable nagle: https://en.wikipedia.org/wiki/Nagle%27s_algorithm */
	char value = 1;
	setsockopt(ConnectSocket, IPPROTO_TCP, TCP_NODELAY, &value, sizeof(value));

}
