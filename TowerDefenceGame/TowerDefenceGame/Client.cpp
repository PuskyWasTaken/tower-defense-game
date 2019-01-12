#include "Client.h"
// #include "stdafx.h"

Client::Client(const char* ip)
{
	/* Init our network */
	network = std::make_unique<ClientNetwork>(ip);

	// send init packet
	//const unsigned int packet_size = sizeof(Packet);
	//char packet_data[packet_size];

	//Packet packet;
	//packet.packet_type = INIT_CONNECTION;

	//packet.serialize(packet_data);

	//NetworkServices::sendMessage(network->ConnectSocket, packet_data, packet_size);
}


Client::~Client()
{
}
