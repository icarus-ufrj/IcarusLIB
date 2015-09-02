#ifndef _IFS_SD_H
#define _IFS_SD_H

#include "Arduino.h"
#include "SD.h"
#include "SPI.h"

namespace IcarusLib{
class IFS_SD {
private:

	/*
	 * Return true if everything is ok with the SD card; and return false otherwise.
	 */ 
	bool InitializeSD(const int cspin);  

	/*
	 *
	 */
	bool OpenfileSD(unsigned preference = 1);

	/*
	 *
	 */
	void ClosefileSD();

	File filesave;
	char* filename;

public:
	IFS_SD(char* namefile, unsigned pin = 10);
	~IFS_SD();
	/*
	 *
	 */
	void PrintlnfileSD(String data);
	
	/*
	 *
	 */
	void PrintfileSD (String data);
};
}
#endif
