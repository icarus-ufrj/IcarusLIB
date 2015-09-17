#include <IFS_SD.h>
#include "Arduino.h"
#include <SD.h>
#include <SPI.h>

using namespace IcarusLib;

IFS_SD *sd = new IFS_SD("test.txt")
const unsigned baudRate = 9600;
long long int counter = 0;

void setup() {
  Serial.begin(baudRate);
}

void loop() {
  sdcard->PrintlnfileSD(String(counter));
  (counter >= 1E6) ? counter = 0 : counter++;
}
