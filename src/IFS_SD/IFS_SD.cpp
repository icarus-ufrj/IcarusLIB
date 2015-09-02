#include "IFS_SD.h"

namespace IcarusLib{

IFS_SD::IFS_SD(char *namefile, unsigned pin){
	if (InitializeSD(pin))
		Serial.println("Error opening the SD card. Please check the configuration");
}
	
IFS_SD::~IFS_SD(){
	ClosefileSD();
}

bool IFS_SD::InitializeSD(const int cspin) {
	return (!SD.begin(cspin)) ? false : true;
}

bool IFS_SD::OpenfileSD (char* path,  unsigned preference) {
	if (!preference) {
		filesave = SD.open(path, FILE_READ);
	  return (filesave) ?  1 : 0; 
	
	} else {	
		filesave= SD.open(path, FILE_WRITE);
	  return (filesave) ?  1 : 0;
	}
}

void IFS_SD::ClosefileSD(){
	filesave.close();
}


	  
void IFS_SD::PrintlnfileSD (String data){
	filesave.println(data);
}	  
	  
void IFS_SD::PrintfileSD (String data){
	filesave.print(data);
}	  
}