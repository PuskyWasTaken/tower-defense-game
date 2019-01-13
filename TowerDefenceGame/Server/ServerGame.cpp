#include "ServerGame.h"
#include "..\NetworkData\NetworkData.h"

unsigned int ServerGame::client_id;

ServerGame::ServerGame()
{
	m_logger = std::make_unique<Logger>(std::cout);
	// id's to assign clients for our table
		client_id = 0;

	// set up the server network to listen 
	network = new ServerNetwork();
}


ServerGame::~ServerGame()
{
}

void ServerGame::update()
{
	// get new clients
	if (network->acceptNewClient(client_id))
	{
		client_id++;
		m_logger->log("Client " + std::to_string(client_id) + " has been conected to the server", Logger::Level::Info);
		
	}
	receiveFromClients();
	
	if (hasBothPlayers() && !gameHasStarted)
	{
		Packet packet;
		packet.type = START_GAME;
		
		sendPacket(defenderId, packet);
		sendPacket(attackerId, packet);
		gameHasStarted = true;
	}


	Sleep(100);
}

void ServerGame::sendActionPackets()
{
	const unsigned int packet_size = sizeof(Packet);
	char packet_data[packet_size];

	Packet packet;
	packet.type = START_GAME;

	packet.serialize(packet_data);

	network->sendToAll(packet_data, packet_size);
}

void ServerGame::sendPacket(const int &clientId, Packet packet)
{
	const unsigned int packetSize = sizeof(Packet);
	char packetData[packetSize];


	packet.serialize(packetData);

	network->sendToClient(packetData, packetSize, clientId);
	
}

void ServerGame::receiveFromClients()
{
	Packet packet;

	//client iterator

	std::map<unsigned int, SOCKET>::iterator iterator;

	for (iterator = network->sessions.begin(); iterator != network->sessions.end(); iterator++)
	{
		int dataLength = network->receiveData(iterator->first, networkData);
				if (dataLength <= 0)
				{
					//no data
					continue;
				}

		int i = 0;
		while (i < (unsigned int)dataLength)
		{
			packet.deserialize(&(networkData[i]));
			i += sizeof(Packet);
		}

		/* After we deserialized all of our data */
		handlePacketData(packet);

	}

}

void ServerGame::handlePacketData( Packet & packet)
{
	switch (packet.type)
	{
		case INIT_CONNECTION:
		{
			m_logger->log(" Server received initialization package from client: " + std::to_string(client_id), Logger::Level::Info);
			sendActionPackets();
			break;
		}
		case ACTION_EVENT:
		{
			m_logger->log(" Received: " + std::to_string(*networkData) + " from: " + std::to_string(client_id), Logger::Level::Info);
			m_logger->log(" Server received action package from client: " + std::to_string(client_id), Logger::Level::Info);
			break;
		}
		case ATTACKER:
		{
			if (gameHasStarted)
			{

				packet.serialize(&networkData[0]);

				sendPacket(defenderId, packet);
				sendPacket(attackerId, packet);
				return;
			}
			else 
				if (attackerId != -1)
				{
					defenderId = client_id;
					m_logger->log(std::to_string(client_id) + "Attacker role was already used, switching role to defender for client: " +
						std::to_string(client_id), Logger::Level::Warning);
					packet.type = PLAYER_ALREADY_TAKEN;
					sendPacket(defenderId, packet);
					Sleep(100);
					return;
				}
				attackerId = client_id;
				m_logger->log(std::to_string(client_id) + "Chose attacker role", Logger::Level::Info);

				break;
			
		}
		case DEFENDER:
		{
			if (gameHasStarted)
			{
				sendPacket(attackerId, packet);
				return;
			}

				if (defenderId != -1)
				{
					attackerId = client_id;
					m_logger->log(std::to_string(client_id) + "Defender role was already used, switching role to attacker for client: " +
						std::to_string(client_id), Logger::Level::Warning);
					packet.type = PLAYER_ALREADY_TAKEN;
					sendPacket(attackerId, packet);
					Sleep(100);
					return;
				}
				defenderId = client_id;
				m_logger->log(std::to_string(client_id) + "Chose defender role", Logger::Level::Info);
				break;
			
		}
		case WON_GAME:
		{
				m_logger->log(std::to_string(client_id) + "Has won the game", Logger::Level::Info);
			if (client_id == attackerId)
			{
				sendPacket(defenderId, packet);		
			}
			if (client_id == defenderId)
			{
				sendPacket(attackerId, packet);
			}
			break;
		}
		case LOST_GAME:
		{
			m_logger->log(std::to_string(client_id) + "Has won the game", Logger::Level::Info);
			if (client_id == attackerId)
			{
				sendPacket(defenderId, packet);
			}
			if (client_id == defenderId)
			{
				sendPacket(attackerId, packet);
			}
			break;
		}

		default:
		{
			m_logger->log("Error in packet type", Logger::Level::Warning);
			break;
		}
	}
}

bool ServerGame::hasBothPlayers()
{
	if (attackerId != -1 && defenderId != -1)
		return true;
	return false;
}
