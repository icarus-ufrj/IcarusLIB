#ifndef _IFS_SD_H
#define _IFS_SD_H

#include "Arduino.h"
#include <SD.h>

namespace IcarusLib{
class IFS_SD {
private:

	/*
	 * Return true if everything is ok with the SD card; and return false otherwise.
	 */ 
	bool InitializeSD (const int cspin);  

	/*
	 *
	 */
	unsigned OpenfileSD(char *path, unsigned preference = 0);

	/*
	 *
	 */
	void ClosefileSD();

	char *filesave;

public:
	IFS_SD(char *namefile, unsigned pin = 10);
	~IFS_SD();
	
	/*
	 *
	 */
	void PrintlnfileSD(char *data);
	
	/*
	 *
	 */
	void PrintfileSD (char *data);
};
}
#endif
