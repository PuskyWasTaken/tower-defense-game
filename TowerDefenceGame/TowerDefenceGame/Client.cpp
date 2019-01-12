#include "Client.h"
#include "..\NetworkData\NetworkData.h"
#include <string.h>

// #include "stdafx.h"

Client::Client(const short playerType, const char* ip)
	: m_playerType(playerType), network(std::make_unique<ClientNetwork>(ip)), logger(std::make_unique<Logger>(std::cout))
{
	/* First Packet */
	sendInitialPacket(playerType);

}
Client::Client(const short playerType)
	: m_playerType(playerType), network(std::make_unique<ClientNetwork>()), logger(std::make_unique<Logger>(std::cout))
{
	/* First Packet */
	sendInitialPacket(playerType);
}


Client::~Client()
{
}

void Client::sendInitialPacket(const short playerType)
{
	/* Initial packet */
	const unsigned int size = sizeof(Packet);
	char data[size];

	Packet packet;
	packet.type = PacketTypes::INIT_CONNECTION;

	packet.serialize(data);

	NetworkServices::sendMessage(network->ConnectSocket, data, size);

	Packet choicePacket;

	/* Send the second packet with our player choice */
	switch (playerType)
	{
		case Client::playerTypes::Attacker:
		{
			choicePacket.type = PacketTypes::ATTACKER;
			break;
		}
		case Client::playerTypes::Defender:
		{
			choicePacket.type = PacketTypes::DEFENDER;
			break;
		}
		default:
		{
			logger->log("Did not recieve a valid player type!", Logger::Level::Error);
			exit((int)Logger::Level::Error);
		}
	}

	/* Send it already */
	choicePacket.serialize(data);
	NetworkServices::sendMessage(network->ConnectSocket, data, size);

}
bool Client::getHasStarted()
{
	return this->m_hasStarted;
}
bool Client::getPlayerChoiceIsValid()
{
	return m_playerChoiceIsValid;
}
void Client::sendActionPackets(const unsigned int actionType)
{ 
	/* Send action packet */
	char data[sizeof(Packet)];

	//std::string send = "This will be sent";
	// char* cStr = new char[send.length() + 1];
	// strcpy(cStr, send.c_str());

	Packet packet;
	packet.type = (PacketTypes)actionType;
	packet.x = -1;
	packet.y = -1;
	
	packet.serialize(data);

	NetworkServices::sendMessage(network->ConnectSocket, data, sizeof(Packet));
}
void Client::sendActionTowerPlaced(const float x, const float y)
{
	/* Send action */
	char data[sizeof(Packet)];

	Packet packet;

	packet.type = SPAWN_TOWER;
	packet.x = x;
	packet.y = y;

	packet.serialize(data);

	NetworkServices::sendMessage(network->ConnectSocket, data, sizeof(Packet));
}
void Client::setPlayerType(const short newType)
{
	m_playerType = newType;
}

void Client::update()
{
	Packet packet;
	int dataLenght = network->receivePackets(m_networkData);

	if (dataLenght <= 0)
	{
		/* Do nothing */
		return;
	}

	for (unsigned int iterator = 0; iterator < (unsigned int)dataLenght; ++iterator)
	{	
		packet.deserialize(&(m_networkData[iterator]));
		iterator += sizeof(Packet);

		switch (packet.type)
		{

			case ACTION_EVENT:

				logger->log("Client received action event packet from server", Logger::Level::Info);
				break;

			case START_GAME:

				if (!m_hasStarted)
					m_hasStarted = true;

				break;
			
			case PLAYER_ALREADY_TAKEN:

				if (m_hasStarted)
					m_playerChoiceIsValid = false;
				break;

			default:

				logger->log("Error in packet types", Logger::Level::Error);
				break;
		}
	}
}
