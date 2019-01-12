#pragma once
#include <winsock2.h>
#include <Windows.h>
#include <fstream>
#include <iostream>
#include "ClientNetwork.h"

class Client
{
public:
	Client();
	~Client();

	std::unique_ptr<ClientNetwork> network;
};

