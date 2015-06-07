#include "IFS_XBEE.h"

using namespace IcarusLib;

int valores = 1;



float finalValue;
float sensorValue = 0;
int sensorPin = A0;
int contador =0;
IFS_XBEE * XBEE;
  
void setup()
{
  XBEE = new IFS_XBEE;
  
  XBEE->InitializeSerialCommunication(9600);
 
}
  
void loop()
{
  
  XBEE->SendPackets (valores);
  
    if(valores == '0')
     {
      sensorValue = analogRead(sensorPin);
      finalValue = sensorValue*(500.0/1023);
      //Envia mensagem de confirmacao
      XBEE->ReceivePackets((String)finalValue);
     }
 
  
}