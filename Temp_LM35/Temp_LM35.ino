/* This code is for educational purpose only.
Author: Cyanogen Hacker
LM35 pin1 -> Arduino +5V
LM35 pin2 -> Arduino A0
LM35 pin3 -> Arduino GND
*/

float temp;
int tempPin = 0;
int redLED = 7;
int greenLED = 8;

void setup()
{
  Serial.begin(9600);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop()
{
  digitalWrite(redLED, LOW);    // switch off the LEDs
  digitalWrite(greenLED, LOW);
  temp = analogRead(tempPin);
  temp = temp * 0.48828125;
  if(temp > 25)
  {
  digitalWrite(redLED, HIGH); // Red led for indicating high temp
  }
  if(temp < 15)
  {
  digitalWrite(greenLED, HIGH); // Green led for indicating low temp
  }
  Serial.print("TEMPRATURE = ");
  Serial.print(temp);
  Serial.print("*C");
  Serial.println();
  delay(1500);
}
