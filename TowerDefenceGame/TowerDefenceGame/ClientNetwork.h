#pragma once

#include <winsock2.h>
#include <Windows.h>
#include "NetworkServices.h"
#include <ws2tcpip.h>
#include <stdio.h>
#include "..\Logging\Logging.h"
#include <iostream>
#include "..\NetworkData\NetworkData.h"

// TO DO: What?!
/* Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib */
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")


class ClientNetwork
{
public:
	ClientNetwork(const char* connectionIp);
	ClientNetwork();
	~ClientNetwork();

	/* For error checking function calls in Winsock library */
	int iResult;
	int receivePackets(char *recievedBuffer);

	/* Socket for client to connect to server */
	SOCKET ConnectSocket;

private: 
	std::unique_ptr<Logger> m_log;

	void init(const char* connectionIp);
};

