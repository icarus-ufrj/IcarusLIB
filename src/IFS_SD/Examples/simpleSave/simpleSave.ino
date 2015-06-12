#include <IFS_SD.h>
#include "Arduino.h"
#include <SD.h>
#include <SPI.h>

using namespace IcarusLib;

const int chipSelect =10;
int finalValue;
int sensorValue = 0;
IFS_SD *sd;
String dataString="aloha";
File *dataFile;


void setup()  
  {
    dataFile = new File;
    sd = new IFS_SD;
    // Open serial communications and wait for port to open:
    Serial.begin(9600);
    Serial.println("Iniciando o cartão SD");
  
    if(sd->InitializeSD (chipSelect))
      return;

    //  Serial.println("Cartao inicializado");
}

void loop() // run over and over
{
  
  
  
  
  if(sd->OpenfileSD(dataFile, "datalog.csv", 1 ))
  {
    
 sd->PrintlnfileSD(dataFile, dataString);
    sd->ClosefileSD(dataFile);
    
  } 
  
 else
  {
    Serial.println ("Erro no cartao");
  } 


  Serial.println("tudo certo");
    
    
    
    delay(1000);
  
}