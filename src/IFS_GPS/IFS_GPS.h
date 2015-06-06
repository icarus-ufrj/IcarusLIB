#ifndef _IFS_GPS_H_
#define _IFS_GPS_H_


#include "Arduino.h"
#include "SoftwareSerial.h"




namespace IcarusLib{
class IFS_GPS {

	SoftwareSerial *softwareserial;

	String GPSdata;

	unsigned pin_GPS_1, pin_GPS_2;

		public:
			
			//constructor for GPS 
			IFS_GPS(unsigned pin_GPS_1=2, unsigned pin_GPS_2=3); 

			

			//destructor
			virtual ~IFS_GPS();


			//it initialize GPS with baud rate
			void initializeGPS (unsigned baudrate);
			
			//it reads what GPS received;
			void readGPS (void);

			String getGPSdata (void);


	


	};
}

#endif