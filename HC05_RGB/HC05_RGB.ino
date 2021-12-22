#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10, 11); // RX, TX
int ledGRN = 4;
int ledBLU = 5;
int ledRED = 6;
int ledWHI = 7; 
int BluetoothData;

void setup() 
{
  bluetooth.begin(9600);
  pinMode(ledGRN,OUTPUT);
  pinMode(ledBLU,OUTPUT);
  pinMode(ledRED,OUTPUT);
  pinMode(ledWHI,OUTPUT);
}

void loop()
{
   if (bluetooth.available())
   {
     BluetoothData=bluetooth.read();
     
     if(BluetoothData==’1′)
       {  
         digitalWrite(ledGRN,1);
         bluetooth.println(“GREEN ON”);
       }
       
      if(BluetoothData==’2′)
       {  
         digitalWrite(ledBLU,1);
         bluetooth.println(“BLUE ON”);
       }
       
      if(BluetoothData==’3′)
       {  
         digitalWrite(ledRED,1);
         bluetooth.println(“RED ON”);
       }
       
      if(BluetoothData==’4′)
       {  
         digitalWrite(ledWHI,1);
         bluetooth.println(“WHITE ON”);
       }
       
      if (BluetoothData==’0′)
       {
         digitalWrite(ledGRN,0);
         digitalWrite(ledBLU,0);
         digitalWrite(ledRED,0);
         digitalWrite(ledWHI,0);
         bluetooth.println(“LEDS OFF”);
       }
     
    }
      delay(100);
}
