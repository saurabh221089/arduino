float tempC;
float reading;
int tempPin = 0;

void setup()
{
Serial.begin(9600);
analogReference(INTERNAL);
}

void loop()
{
reading = analogRead(tempPin);
tempC = reading / 9.31;
Serial.print("TEMPRATURE = ");
 Serial.print(tempC);
 Serial.print("*C");
 Serial.println();
 delay(1500);
}
