#include "Client.h"
#include "NetworkData.h"
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
	packet.type = INIT_CONNECTION;

	packet.serialize(data);

	NetworkServices::sendMessage(network->ConnectSocket, data, size);
}
void Client::sendActionPackets()
{ 
	/* Send action packet */
	const unsigned int size = sizeof(Packet);
	char data[size];

	Packet packet;
	packet.type = ACTION_EVENT;

	packet.serialize(data);

	NetworkServices::sendMessage(network->ConnectSocket, data, size);
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

			sendActionPackets();

			logger->log("Client received action event packet from server", Logger::Level::Info);
			break;

		default:

			logger->log("Error in packet types", Logger::Level::Error);
			break;
		}
	}
}
