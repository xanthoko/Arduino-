#include <seg3.h>

#include <dht.h>

dht DHT;
seg3 a;

#define DHT11_PIN 13


int buttonCount;
int buttonState;
int lastButtonState=LOW;
int buttonPin=9;

void setup()
{
  pinMode(buttonCount,INPUT);
}

void loop()
{
  // READ DATA
  Serial.print("DHT11, \t");
  int chk = DHT.read11(DHT11_PIN);
  switch (chk)
  {
    case DHTLIB_OK:  
                Serial.print("OK,\t"); 
                break;
    case DHTLIB_ERROR_CHECKSUM: 
                Serial.print("Checksum error,\t"); 
                break;
    case DHTLIB_ERROR_TIMEOUT: 
                Serial.print("Time out error,\t"); 
                break;
    case DHTLIB_ERROR_CONNECT:
        Serial.print("Connect error,\t");
        break;
    case DHTLIB_ERROR_ACK_L:
        Serial.print("Ack Low error,\t");
        break;
    case DHTLIB_ERROR_ACK_H:
        Serial.print("Ack High error,\t");
        break;
    default: 
                Serial.print("Unknown error,\t"); 
                break;
  }
  // DISPLAY DATA
  Serial.print(DHT.humidity, 1);
  Serial.print(",\t");
  Serial.println(DHT.temperature, 1);

 
   // PRINT DATA ON SEGMENT
   for(int j=0;j<2000;j++){
   buttonState=digitalRead(buttonPin);
   if(lastButtonState!=buttonState){
    if(buttonState==HIGH)
      buttonCount++;
    }
    // CHANGE THE PRINTING DATA WITH A BUTTON PRESS
    if(buttonCount%2==0)
      a.disp(DHT.temperature);
    else
      a.disp(DHT.humidity);  
    lastButtonState=buttonState;
  
   }

}
