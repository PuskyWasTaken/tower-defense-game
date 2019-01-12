#include "ServerGame.h"


int main()
{
	ServerGame * server;

	server = new ServerGame();

	while (true)
	{
		server->update();
	}

	return 0;
}