#pragma once
#include <winsock2.h>
#include <Windows.h>
#include <fstream>
#include <iostream>
#include "ClientNetwork.h"

class Client
{
public:
	Client(const short playerType, const char* ip);
	Client(const short playerType);
	~Client();

private:

	std::unique_ptr<ClientNetwork> network;
	
	short m_playerType;
	char m_networkData[MAX_PACKET_SIZE]; // RIP
	std::unique_ptr<Logger> logger;
	
private:

	void sendInitialPacket(const short playerType);
	void sendActionPackets();

public:

	void setPlayerType(const short newType);
	void update();

	enum playerTypes
	{
		Defender,
		Attacker
	};

};

