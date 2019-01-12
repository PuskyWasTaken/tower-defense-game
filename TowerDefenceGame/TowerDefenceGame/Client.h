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
	char m_networkData[maxPacketSize]; // RIP
	std::unique_ptr<Logger> logger;

private:
	bool m_hasStarted = false;
	bool m_playerChoiceIsValid = true;
	bool m_recievedFromAttacker = false;
	bool m_recievedFromDefender = false;
	
private:

	void sendInitialPacket(const short playerType);

public:

	bool getHasStarted();
	bool getPlayerChoiceIsValid();

	void setPlayerChoiceIsValid(const bool newValue);
	
	
	void sendActionPackets(const unsigned int actionType);
	void sendActionTowerPlaced(const float x, const float y);
	void setPlayerType(const short newType);
	void update();

	enum playerTypes
	{
		Defender,
		Attacker
	};

};

