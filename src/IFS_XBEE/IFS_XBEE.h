#ifndef _IFS_XBEE_H
#define _IFS_XBEE_H

#include <Arduino.h>

namespace IcarusLib{
class IFS_XBEE {
private:
	unsigned Baudrate;
	char *lastpacketreceived;
	int lastpacketsent;

	/*
	 *
	 */
	void InitializeSerialCommunication (const unsigned baudrate);

public:
	IFS_XBEE(unsigned baudrate);
	~IFS_XBEE();

	/*
	 *
	 */
	void SendPackets (int &packetsent);
	
	/*
	 *
	 */
	void ReceivePackets(char *packetreceived);



};
}

#endif
