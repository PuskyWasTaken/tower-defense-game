#pragma once

#include "ServerNetwork.h"

class ServerGame
{
public:
	ServerGame();
	~ServerGame();

	void update();


	void sendActionPackets();
	void sendPacket(const int &clientId, Packet packet);


private:
	// IDs for the clients connecting for table in ServerNetwork 
	static unsigned int client_id;

	// The ServerNetwork object 
	ServerNetwork* network;

	int attackerId = -1;
	int defenderId = -1;

	void receiveFromClients();
	void handlePacketData(Packet& packet);

private:
	std::unique_ptr<Logger> m_logger;
	char networkData[maxPacketSize];
	bool gameHasStarted = false;

	bool hasBothPlayers();
};

