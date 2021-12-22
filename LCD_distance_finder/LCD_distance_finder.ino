#include <LiquidCrystal.h>

#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin

int maximumRange = 400; // Maximum range needed
int minimumRange = 0; // Minimum range needed
float duration, distance,inch; // Duration used to calculate distance

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
Serial.begin(9600);
lcd.begin(16, 2);
lcd.setCursor(2, 0);                          // Set LCD cursor position (column, row)
lcd.print("Distance");                      // Print text to LCD
lcd.setCursor(3, 1);                          // Set LCD cursor position (column,row)  
lcd.print("Finder");                        // Print text to LCD
delay(3000);
lcd.clear();
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}

void loop()
{
digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 //Calculate the distance (in inches)
 inch=distance*0.3937;
 
 if (distance >= maximumRange || distance <= minimumRange){
 Serial.println("Out of Range");
 lcd.clear();
 lcd.setCursor(1, 0);                                       // Set LCD cursor position (column 1, row 0)
 lcd.print("Out of Range");                                 // Print text to LCD
 }
 else if (distance <=20)
 {
 Serial.println(distance);
 tone(9,4000,20);
 lcd.setCursor(0, 0);                                           // Set LCD cursor position (column 1, row 0)
 lcd.print("Centimeter:");                                 // Print text to LCD
 lcd.print(distance);
 lcd.setCursor(0, 1);                                           // Set LCD cursor position (column 0, row 1)
 lcd.print("Inches :  ");                                     // Print text to LCD
 lcd.print(inch);                                          // Set LCD cursor position (column 12, row 1)
 }
 else {
 Serial.println(distance);
 lcd.setCursor(0, 0);                                           // Set LCD cursor position (column 0, row 0)
 lcd.print("Centimeter:");                                 // Print text to LCD
 lcd.print(distance);
 lcd.setCursor(0, 1);                                           // Set LCD cursor position (column 0, row 1)
 lcd.print("Inches :  ");                                     // Print text to LCD
 lcd.print(inch);                                          // Set LCD cursor position (column 12, row 1) 
 }
delay(400);
}
