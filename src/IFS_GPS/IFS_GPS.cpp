#include "IFS_GPS.h"


namespace IcarusLib{
	
	IFS_GPS::IFS_GPS (unsigned pin1, unsigned pin2)
	{
			softwareserial= new SoftwareSerial (pin1, pin2); // it calls the constructor of SoftwareSerialObject; - REVERRRR
			pin_GPS_1=pin1;
			pin_GPS_2=pin2;
	}




	IFS_GPS::~IFS_GPS()
	{
		delete softwareserial;
	}



	//it initialize GPS with baud rate
			void IFS_GPS::initializeGPS (unsigned baudrate)
			{
				//it calls the function in SoftwareSerial that initializes the baudrate of GPS
				softwareserial->begin(baudrate);

			}
			
			//it reads what GPS received;
			void IFS_GPS::readGPS ()
			{
				char entrada=0;
				GPSdata="";

				while((entrada = softwareserial->read()) != 10) {

						if(entrada > 0)

							GPSdata += entrada;

						}


			}

			String IFS_GPS::getGPSdata(void)
			{
				return GPSdata;
			}


}