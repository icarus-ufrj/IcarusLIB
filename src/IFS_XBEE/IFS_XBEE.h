#ifndef _IFS_XBEE_H
#define _IFS_XBEE_H

#include <Arduino.h>

namespace IcarusLib{
class IFS_XBEE {

	
	unsigned Baudrate;
	String lastpacketreceived;
	int lastpacketsent;
	public:

		IFS_XBEE();

		~IFS_XBEE();

		void InitializeSerialCommunication (unsigned baudrate);

		//from xbee that computer to arduino or, in other word, form coordinator to ...
		void SendPackets (int &packetsent);

		void ReceivePackets(String packetreceived);



};
}

#endif
