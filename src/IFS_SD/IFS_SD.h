#ifndef _IFS_SD_H
#define _IFS_SD_H

#include "Arduino.h"
#include <SD.h>

namespace IcarusLib{
	
class IFS_SD {

	//SD *sd; //pointer to sd object

	unsigned sdtype; //it 

	

		


	public:

		IFS_SD();

		~IFS_SD();

		//return 1 if everything is ok; return 0 if there is something wrong
		unsigned InitializeSD (unsigned = 10); 


		unsigned OpenfileSD(File &namefile, String path, unsigned preference=0);
		
		void ClosefileSD(File &namefile);

		void PrintlnfileSD(File &namefile, String data , String BASE);

		void PrintfileSD (File &namefile, String data, String BASE);



	};
}
#endif
