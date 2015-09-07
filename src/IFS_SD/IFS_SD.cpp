#include "IFS_SD.h"

namespace IcarusLib{

IFS_SD::IFS_SD(char* namefile, unsigned pin){
	filename = namefile;
	if (InitializeSD(pin)){
		Serial.println("Error opening the SD card. Please check the configuration");
		return;
	}

	if(OpenfileSD()){
		Serial.println("Error opening the selected file. Please, check if the file exist.");
		return;
	}
}
	
IFS_SD::~IFS_SD(){
	ClosefileSD();
}

bool IFS_SD::InitializeSD(const int cspin) {
	return (!SD.begin(cspin)) ? 0 : 1;
}

bool IFS_SD::OpenfileSD (unsigned preference) {
	if (!preference) {
		filesave = SD.open(filename, FILE_READ);
	  return (!filesave) ?  0 : 1; 
	
	} else {	
		filesave= SD.open(filename, FILE_WRITE);
	  return (!filesave) ?  0 : 1;
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