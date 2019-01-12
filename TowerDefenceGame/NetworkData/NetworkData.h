#pragma once
#include <string.h>

/* Basically our globals class for the Network stuff. */
static const unsigned int maxPacketSize = 1000000;
static const int32_t defaultBufferLength = 512;

/* Port to connect sockets through */
static const char* defaultServerPort = "27015";

enum PacketTypes {

	INIT_CONNECTION,
	ACTION_EVENT,
	ATTACKER,
	DEFENDER,
	START_GAME
};

class Packet {

public:

	unsigned int type;

	void serialize(char * data) {
		memcpy(data, this, sizeof(Packet));
	}

	void deserialize(char * data) {
		memcpy(this, data, sizeof(Packet));
	}
};
