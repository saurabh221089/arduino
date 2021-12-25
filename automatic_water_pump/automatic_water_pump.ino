#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int RELAY1 = 10;
const int SENSOR_PIN = A0;  /* Connect Soil moisture analog sensor pin to A0 */

void setup() {
  Serial.begin(9600); /* Define baud rate for serial communication */
  lcd.begin(16, 2);
  lcd.setCursor(1, 0);                          // Set LCD cursor position (column, row)
  lcd.print("Soil Moisture");                      // Print text to LCD
  lcd.setCursor(3, 1);                          // Set LCD cursor position (column,row)  
  lcd.print("Sensor");                        // Print text to LCD
  delay(3000);
  lcd.clear();
  pinMode(RELAY1, OUTPUT);                 // initialize digital pin as an output.
}

void loop() {
  float moisture_percentage;

  moisture_percentage = ( 100.00 - ( (analogRead(SENSOR_PIN)/1023.00) * 100.00 ) );

  Serial.print("Soil Moisture(in Percentage) = ");
  Serial.print(moisture_percentage);
  Serial.println("%");
  if (moisture_percentage < 65){
   lcd.clear();
   lcd.setCursor(0, 0);                                       // Set LCD cursor position (column 0, row 0)
   lcd.print("Moisture = ");
   lcd.print(moisture_percentage);                                 // Print text to LCD
   lcd.setCursor(0, 1);                                       // Set LCD cursor position (column 0, row 1)
   lcd.print("Motor ON");                                 // Print text to LCD
   digitalWrite(RELAY1, LOW);                               // Turn ON the motor
   }
  else
   {
   lcd.clear();
   lcd.setCursor(0, 0);                                       // Set LCD cursor position (column 0, row 0)
   lcd.print("Moisture = ");
   lcd.print(moisture_percentage);                                 // Print text to LCD
   lcd.setCursor(0, 1);                                       // Set LCD cursor position (column 0, row 1)
   lcd.print("Motor OFF");                                 // Print text to LCD
   digitalWrite(RELAY1, HIGH);                               // Turn OFF the motor
   }
  delay(2000);
}
