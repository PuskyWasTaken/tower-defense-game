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

	std::unique_ptr<ClientNetwork> m_network;
	
	short m_playerType;
	char m_networkData[maxPacketSize]; // RIP
	std::unique_ptr<Logger> m_logger;

private:

	bool m_hasStarted = false;
	bool m_playerChoiceIsValid = true;

	bool m_recievedFromAttacker = false;
	bool m_recievedFromDefender = false;

	int m_enemyWon = Uninitialized;


	Packet m_attackerPacket;
	Packet m_defenderPacket;

private:

	void sendInitialPacket(const short playerType);

public:

	/* The game should only access what it needs to */

	bool getHasStarted();
	bool getPlayerChoiceIsValid();
	bool getRecievedFromAttacker();
	bool getRecievedFromDefender();
	int getEnemyWon();

	void setRecievedFromAttacker(const bool newValue);
	void setRecievedFromDefender(const bool newValue);
	void setPlayerChoiceIsValid(const bool newValue);
	void setEnemyWon(const int newValue);

	int getAttackerData();
	float getDefenderX();
	float getDefenderY();
	int getDefenderData();
		
	void sendActionPackets(const unsigned int actionType);
	void sendActionTowerPlaced(const float x, const float y, const int type);
	void sendActionEnemySpawned(const int enemyType);
	void setPlayerType(const short newType);
	void update();

	enum playerTypes
	{
		Defender,
		Attacker
	};

	enum enemyState
	{
		Uninitialized = -1,
		EnemyLost,
		EnemyWon,
	};

};

