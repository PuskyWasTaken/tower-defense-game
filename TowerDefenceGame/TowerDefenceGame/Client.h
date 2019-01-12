#pragma once
#include <winsock2.h>
#include <Windows.h>
#include <fstream>
#include <iostream>
#include "ClientNetwork.h"

class Client
{
public:
	Client(const char* ip);
	Client();
	~Client();

	std::unique_ptr<ClientNetwork> network;
};

