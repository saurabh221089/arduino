#include <SoftwareSerial.h>

SoftwareSerial BTSerial(11, 10); // RX | TX

void setup() 
{
  pinMode(9, OUTPUT); // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  pinMode(8,OUTPUT);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  Serial.begin(9600);
  BTSerial.begin(38400);  // HC-05 default speed in AT command more
  BTSerial.write("AT+ORGL");
  delay(500);
  BTSerial.write("AT+RMAAD");
  delay(500);
  BTSerial.write("AT+ROLE=1");
  delay(500);
  BTSerial.write("AT+RESET");
  delay(500);
  BTSerial.write("AT+CMODE=1");
  delay(500);
  BTSerial.write("AT+INQM=0,5,5");
  delay(500);
  BTSerial.write("AT+PSWD=1234");
  delay(500);
  BTSerial.write("AT+INIT");
  delay(500);
  BTSerial.write("AT+INQ");
  Serial.println("Enter AT commands:");
}

void loop()
{
  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (BTSerial.available())
    Serial.write(BTSerial.read());
  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
    BTSerial.write(Serial.read());
}


