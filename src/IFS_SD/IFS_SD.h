#ifndef _IFS_SD_H
#define _IFS_SD_H

#include "Arduino.h"
#include <SD.h>

namespace IcarusLib{
class IFS_SD {
private:
	unsigned sdtype; //it 

public:
	IFS_SD();
	~IFS_SD();

	//return 1 if everything is ok; return 0 if there is something wrong
	unsigned InitializeSD (const int cspin = 10); 
	unsigned OpenfileSD(File *namefile, char *path, unsigned preference=0);
	void ClosefileSD(File *namefile);
	void PrintlnfileSD(File *namefile, String &data);
	void PrintfileSD (File *namefile, String data);
};
}
#endif
