#include "IFS_XBEE.h"


namespace IcarusLib{


	IFS_XBEE::IFS_XBEE(){};


	IFS_XBEE::~IFS_XBEE(){};

	void IFS_XBEE::InitializeSerialCommunication(unsigned baudrate)
	{
		Baudrate = baudrate;
		Serial.begin(baudrate);

	}

	//sent from router to coordinator - Icarus case: router collecting sensor data and coordinator on computer 
	void IFS_XBEE::ReceivePackets( String packetreceived)
	{

		if(Serial.available()>0)
		{	
			Serial.print(packetreceived);
			lastpacketreceived=packetreceived;
		}
	}

	//sent from coordinator to router - Icarus case: coordinator on computer and router collecting sensor data
	void IFS_XBEE::SendPackets(int &packetsent)
	{
		if(Serial.available()>0)
		{	
			packetsent=Serial.read();
			lastpacketsent = packetsent;
		}	
	}

}
