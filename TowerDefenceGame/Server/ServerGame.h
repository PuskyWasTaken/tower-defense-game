#pragma once

#include "ServerNetwork.h"

class ServerGame
{
public:
	ServerGame();
	~ServerGame();

	void update();

private:
	// IDs for the clients connecting for table in ServerNetwork 
	static unsigned int client_id;

	// The ServerNetwork object 
	ServerNetwork* network;
};

