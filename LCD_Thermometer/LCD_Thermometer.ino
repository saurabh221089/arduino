 
/*
Displays Current, 8 sec Average, Max and Min Temperature.

 To wire your LCD screen to your Arduino, connect the following pins: 
LCD Pin 6 to digital pin 12 
LCD Pin 4 to digital pin 11 
LCD Pin 11 to digital pin 5 
LCD Pin 12 to digital pin 4 
LCD Pin 13 to digital pin 3 
LCD Pin 14 to digital pin 2 
Additionally, wire a 10K pot to +5V and GND, with it's wiper (output) to LCD screens VO pin (pin3). 
*/
 
#include <LiquidCrystal.h>                                       // include the LCD driver library

float tempC = 0;                                                 // Variable for holding Celcius temp (floating for decimal points precision)
float tempf = 0;                                                 // variable for holding Fareghneit temp
float sensor = 0;
float samples[8];                                                // Array to hold 8 samples for Average temp calculation
float maxi = 0,mini = 100;                                       // Max/Min temperature variables with initial values.
int i;
                                              
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);                          // initialize the library with the numbers of the interface pins

void setup()
{
Serial.begin(9600);                                             // Opens serial port, sets data rate to 9600 bps
 
lcd.begin(16, 2);                                               // Set up the LCD's number of columns and rows: 
lcd.setCursor(3, 0);                                            // Set LCD cursor position (column, row)
lcd.print("Cyanogen's");                                      // Print text to LCD
lcd.setCursor(2, 1);                                            // Set LCD cursor position (column,row)  
lcd.print("Thermometer");                                       // Print text to LCD
delay(2000); 
lcd.noDisplay();
delay(2000);
lcd.display();
lcd.clear();                                                    // Clear LCD
}

void loop()
{
Serial.println("**********************");
Serial.println("You are looking at a project built by Cyanogen Hacker.");  // Print text to Serial monitor
Serial.println("Feel free to use and modify as needed.");
Serial.println("**********************"); 
Serial.print("TMP36 Raw data: ");                               // Print text to Serial monitor  
Serial.println(analogRead(0));                           // Displays on serial monitor the sampled value before conversion to real Temperature reading

for(i = 0;i<=7;i++)
{                                                              // gets 8 samples of temperature
sensor= analogRead(0);
samples[i] = ((5000*sensor)/1024)-500;      // conversion math of TMP36 sample to readable temperature and stores result to samples array.  
samples[i] = samples[i]/10;
Serial.println(samples[i]);                                    // Print samples [i] to sertiual monitor                                             
lcd.setCursor(0, 0);                                           // Set LCD cursor position (column 0, row 0)
lcd.print("Current Temp is: ");                                // Print text to LCD
lcd.setCursor(1, 1);                                           // Set LCD cursor position (column 1, row 1)
lcd.print("  Celcius   ");                                     // Print text to LCD
lcd.setCursor(12, 1);                                          // Set LCD cursor position (column 12, row 1)
lcd.print(samples[i]);                                         // print current Temp sample to LCD
tempC = tempC + samples[i];                                    // do the addition for average temperature 
delay(800);                                                    // wait 800ms
}                                                              // END of FOR loop

Serial.println("");                                            // Blank line for spacing in the serial monitor
Serial.println("");                                            // Blank line for spacing in the serial monitor 
tempC = tempC/8.0;                                             // calculated the averare of 8 samples in Celcius

tempf = (tempC * 1.8) + 32;                                   // converts to fahrenheit 

if(tempC > maxi) {maxi = tempC;}                               // set max temperature
if(tempC < mini) {mini = tempC;}                               // set min temperature

// Send Results to Serial Monitor
Serial.println("New measurement:");
Serial.print(" Average Temperature in Celcius is " );
Serial.println(tempC);
Serial.print(" Average Temperature in Farenait is " );
Serial.println(tempf);
Serial.print(" MAX Temperature in Celcius is " );
Serial.println(maxi);
Serial.print(" MIN Temperature in Celcius is " );
Serial.println(mini);
// Send results to LCD.
lcd.setCursor(0, 1);                                           // Set LCD cursor position (column 0, line 1) 
lcd.print(" Fahrenheit ");                                     // Print text to LCD 
lcd.setCursor(12, 1);                                          // Set LCD cursor position (column 12, line 1) 
lcd.print(tempf);                                              // Send the data to the LCD 

delay(6000);                                                   // Wait 3 seconds to display the Fahrenheit temp and 3 seconds to display results to LCD screen befor starting the loop again = 6 seconds.
tempC = 0;                                                     // Set tempC to 0 so calculations can be done again
 }
