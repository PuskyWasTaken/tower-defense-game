#include "Client.h"
#include "..\NetworkData\NetworkData.h"
#include <string.h>

Client::Client(const short playerType, const char* ip)
	: m_playerType(playerType), m_network(std::make_unique<ClientNetwork>(ip)), m_logger(std::make_unique<Logger>(std::cout))
{
	/* First Packet */
	sendInitialPacket(playerType);

}
Client::Client(const short playerType)
	: m_playerType(playerType), m_network(std::make_unique<ClientNetwork>()), m_logger(std::make_unique<Logger>(std::cout))
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

	NetworkServices::sendMessage(m_network->ConnectSocket, data, size);
	m_logger->log("Client just sent the INIT_CONNECTION packet to the server", Logger::Level::Info);


	Packet choicePacket;

	/* Send the second packet with our player choice */
	switch (playerType)
	{
		case Client::playerTypes::Attacker:
		{
			choicePacket.type = PacketTypes::ATTACKER;
			m_logger->log("Client just sent the ATTACKER packet to the server", Logger::Level::Info);

			break;
		}
		case Client::playerTypes::Defender:
		{
			choicePacket.type = PacketTypes::DEFENDER;
			m_logger->log("Client just sent the DEFENDER packet to the server", Logger::Level::Info);

			break;
		}
		default:
		{
			m_logger->log("Did not recieve a valid player type!", Logger::Level::Error);
			Sleep(5000);
			exit((int)Logger::Level::Error);
		}
	}

	/* Send it already */
	choicePacket.serialize(data);
	NetworkServices::sendMessage(m_network->ConnectSocket, data, size);


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

	NetworkServices::sendMessage(m_network->ConnectSocket, data, sizeof(Packet));
	m_logger->log("Client just sent a packet to the server", Logger::Level::Info);

}
void Client::sendActionTowerPlaced(const float x, const float y, const int type)
{
	/* Send action */
	char data[sizeof(Packet)];

	Packet packet;

	packet.type = PacketTypes::DEFENDER;
	packet.x = x;
	packet.y = y;
	packet.recievedType = type;

	packet.serialize(data);

	NetworkServices::sendMessage(m_network->ConnectSocket, data, sizeof(Packet));
	m_logger->log("Client just sent a DEFENDER packet to the server(placing a tower)", Logger::Level::Info);
}

void Client::sendActionEnemySpawned(const int enemyType)
{
	/* Send action */
	char data[sizeof(Packet)];

	Packet packet;

	packet.type = PacketTypes::ATTACKER;
	packet.x = -1;
	packet.y = -1;
	packet.recievedType = enemyType;


	packet.serialize(data);

	NetworkServices::sendMessage(m_network->ConnectSocket, data, sizeof(Packet));
	m_logger->log("Client just sent a ATTACKER packet to the server(spawning enemy)", Logger::Level::Info);
}

void Client::update()
{
	Packet packet;
	int dataLenght = m_network->receivePackets(m_networkData);

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

			case PacketTypes::ACTION_EVENT:

				m_logger->log("Client received ACTION_EVENT packet from server", Logger::Level::Info);
				break;

			case PacketTypes::START_GAME:

				if (!m_hasStarted)
					m_hasStarted = true;

				m_logger->log("Client received START_GAME packet from server", Logger::Level::Info);
				break;
			
			case PacketTypes::PLAYER_ALREADY_TAKEN:

				if (m_playerChoiceIsValid)
					m_playerChoiceIsValid = false;

				m_logger->log("Client received PLAYER_ALREADY_TAKEN packet from server", Logger::Level::Info);
				break;

			case PacketTypes::ATTACKER:

				/* We recieved data from the attacker */
				if (!m_recievedFromAttacker)
				{
					m_recievedFromAttacker = true;
					m_attackerPacket = packet;
				}

				m_logger->log("Client received ATTACKER packet from server", Logger::Level::Info);
				break;


			case PacketTypes::DEFENDER:

				/* We recieved data from the defender */
				if (!m_recievedFromDefender)
				{
					m_recievedFromDefender = true;
					m_defenderPacket = packet;
				}

				m_logger->log("Client received DEFENDER packet from server", Logger::Level::Info);
				break;

			case PacketTypes::WON_GAME:

				if (m_enemyWon == enemyState::Uninitialized)
					m_enemyWon = enemyState::EnemyWon;

				m_logger->log("Client received WON_GAME packet from server", Logger::Level::Info);
				break;

			case PacketTypes::LOST_GAME:

				if (m_enemyWon == enemyState::Uninitialized)
					m_enemyWon = enemyState::EnemyLost;

				m_logger->log("Client received LOST_GAME packet from server", Logger::Level::Info);
				break;

			default:

				m_logger->log("Error in packet types", Logger::Level::Error);
				break;
		}
	}
}

void Client::setPlayerType(const short newType)
{
	m_playerType = newType;
}
bool Client::getHasStarted()
{
	return this->m_hasStarted;
}
bool Client::getPlayerChoiceIsValid()
{
	return m_playerChoiceIsValid;
}
bool Client::getRecievedFromAttacker()
{
	return m_recievedFromAttacker;
}
bool Client::getRecievedFromDefender()
{
	return m_recievedFromDefender;
}
void Client::setRecievedFromAttacker(const bool newValue)
{
	if (newValue != m_recievedFromAttacker)
		m_recievedFromAttacker = newValue;
}
void Client::setRecievedFromDefender(const bool newValue)
{
	if (newValue != m_recievedFromDefender)
		m_recievedFromDefender = newValue;
}
void Client::setPlayerChoiceIsValid(const bool newValue)
{
	if (newValue != m_playerChoiceIsValid)
		m_playerChoiceIsValid = newValue;
}
void Client::setEnemyWon(const int newValue)
{
	m_enemyWon = newValue;
}


int Client::getEnemyWon()
{
	return m_enemyWon;
}
int Client::getAttackerData()
{
	return m_attackerPacket.recievedType;
}
float Client::getDefenderX()
{
	return m_defenderPacket.x;
}
float Client::getDefenderY()
{
	return m_defenderPacket.y;
}
int Client::getDefenderData()
{
	return m_defenderPacket.recievedType;
}