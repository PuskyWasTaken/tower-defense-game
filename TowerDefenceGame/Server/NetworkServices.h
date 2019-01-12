#pragma once
#pragma comment(lib, "Ws2_32.lib")
#include <winsock2.h>
#include <Windows.h>
#include "..\NetworkData\NetworkData.h"


class NetworkServices
{
public:
	NetworkServices();
	~NetworkServices();

public:
	static int sendMessage(SOCKET curSocket, char * message, int messageSize);
	static int receiveMessage(SOCKET curSocket, char * buffer, int bufSize);
};

