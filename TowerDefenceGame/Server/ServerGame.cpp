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
	
	if (hasBothPlayers())
	{
	
		sendPacket(attackerId, START_GAME);
		sendPacket(defenderId, START_GAME);
	}
}

void ServerGame::sendActionPackets()
{
	const unsigned int packet_size = sizeof(Packet);
	char packet_data[packet_size];

	Packet packet;
	packet.type = ACTION_EVENT;

	packet.serialize(packet_data);

	network->sendToAll(packet_data, packet_size);
}

void ServerGame::sendPacket(const int &clientId, PacketTypes packetType)
{
	const unsigned int packetSize = sizeof(Packet);
	char packetData[packetSize];

	Packet packet;
	packet.type = packetType;

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
				m_logger->log(" Server received action package from client: " + std::to_string(client_id) , Logger::Level::Info);
				break;
			}
			case ATTACKER:
			{
				if (attackerId != -1)
				{
					closesocket(closesocket(network->sessions[client_id]));
				//	network->sessions.erase(client_id);
					m_logger->log(std::to_string(client_id) + "Attacker role was already used, connection closed to" + 
						std::to_string(client_id), Logger::Level::Warning);
					break;
				}
				attackerId = client_id;
				m_logger->log(std::to_string(client_id) + "Chose attacker role", Logger::Level::Info);	
				break;
			}
			case DEFENDER:
			{
				if (defenderId != -1)
				{
					closesocket(closesocket(network->sessions[client_id]));
					//network->sessions.erase(client_id);
					m_logger->log(std::to_string(client_id) + "Defender role was already used, connection closed to" +
						std::to_string(client_id), Logger::Level::Warning);
					break;
				}
				defenderId = client_id;
				m_logger->log(std::to_string(client_id) + "Chose defender role", Logger::Level::Info);
				break;
			}
			
			default:
			{
				m_logger->log("Error in packet type", Logger::Level::Warning);
				break;
			}

			}
		}

	}

}

bool ServerGame::hasBothPlayers()
{
	if (attackerId != -1 && defenderId != -1)
		return true;
	return false;
}
