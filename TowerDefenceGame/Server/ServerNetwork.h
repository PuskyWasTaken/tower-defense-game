#pragma once
#pragma comment(lib, "Ws2_32.lib")

#include <winsock2.h>
#include <Windows.h>
#include "NetworkServices.h"
#include <ws2tcpip.h>
#include <map>
#include <stdio.h> 

#include "..\Logging\Logging.h"

class ServerNetwork
{
public:
	ServerNetwork();
	~ServerNetwork();

	SOCKET listenSocket;

	SOCKET clientSocket;

	int iResult;


	std::map<unsigned int, SOCKET> sessions;

	bool acceptNewClient(unsigned int &id);
	int receiveData(unsigned int clientId, char * receiveBuffer);
	void sendToAll(char* packets, int totalSize);
	void sendToClient(char* packets, int totalSize, int clientId);

private:
	std::unique_ptr<Logger> m_logger;

};

