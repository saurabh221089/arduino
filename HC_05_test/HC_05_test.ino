// This program shown how to control arduino from PC Via Bluetooth
// D11   >>>  Rx
// D10   >>>  Tx
//Written By Mohannad Rawashdeh
//for http://www.genotronex.com/

#include <SoftwareSerial.h>// import the serial library

SoftwareSerial Genotronex(10, 11); // RX, TX
int ledpin=13; // led on D13 will show blink on / off
int BluetoothData; // the data given from Computer

void setup() {
  Genotronex.begin(9600);
  Genotronex.println("Hi from HC-05 to Android.. please press 1 or 0 blink LED ..");
  pinMode(ledpin,OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
   if (Genotronex.available()){
BluetoothData=Genotronex.read();
   if(BluetoothData=='1'){   // if number 1 pressed ....
   digitalWrite(ledpin,1);
   Genotronex.println("LED  On D13 ON ! ");
   }
   if(BluetoothData=='3'){   // if number 1 pressed ....
   digitalWrite(3, 0);
   digitalWrite(5, 1);
   digitalWrite(6, 1);
   Genotronex.println("Pin 3 activated ! ");
   }
   if(BluetoothData=='5'){   // if number 1 pressed ....
   digitalWrite(3, 1);
   digitalWrite(5, 0);
   digitalWrite(6, 1);
   Genotronex.println("Pin 5 activated ! ");
   }
   if(BluetoothData=='6'){   // if number 1 pressed ....
   digitalWrite(3, 1);
   digitalWrite(5, 1);
   digitalWrite(6, 0);
   Genotronex.println("Pin 6 activated ! ");
   }
  if (BluetoothData=='0'){// if number 0 pressed ....
  digitalWrite(ledpin,0);
   Genotronex.println("LED  On D13 Off ! ");
  }
}
delay(100);
}
