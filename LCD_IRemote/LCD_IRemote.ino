#include "Wire.h" // for I2C bus
#include "LiquidCrystal_I2C.h" // for I2C bus LCD module (http://www.dfrobot.com/wiki/index.php/I2C/TWI_LCD1602_Module_(SKU:_DFR0063))
 
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
#include <IRremote.h> // use the library for IR
int receiver = 11; // pin 1 of IR receiver to Arduino digital pin 11
IRrecv irrecv(receiver); // create instance of 'irrecv'
decode_results results;
void setup()
{
  lcd.init();          // initialize the lcd
  lcd.backlight(); // turn on LCD backlight
  irrecv.enableIRIn(); // Start the receiver
}
void translateIR() // takes action based on IR code received
// describing Sony IR codes on LCD module
{
  switch(results.value)
  {
    case 0x37EE: lcd.println(" Favourite      "); break;
    case 0xA90: lcd.println(" Power button   "); break;
    case 0x290: lcd.println(" mute           "); break;
    case 0x10:  lcd.println(" one            "); break;
    case 0x810:  lcd.println("  two           "); break;
    case 0x410:  lcd.println(" three          "); break;
    case 0xC10:  lcd.println(" four           "); break;
    case 0x210:  lcd.println(" five           "); break;
    case 0xA10:  lcd.println(" six            "); break;
    case 0x610:  lcd.println(" seven          "); break;
    case 0xE10:  lcd.println(" eight          "); break;
    case 0x110:  lcd.println(" nine           "); break;
    case 0x910:  lcd.println(" zero           "); break;
    case 0x490:  lcd.println(" volume up      "); break;
    case 0xC90:  lcd.println(" volume down    "); break;
    case 0x90:   lcd.println(" channel up     "); break;
    case 0x890:  lcd.println(" channel down   "); break;
    default: lcd.println(" other button   ");
  }
  delay(500);
  lcd.clear();
}
void loop()
{
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    translateIR();
    for (int z=0; z<2; z++) // ignore 2nd and 3rd signal repeat
    {
      irrecv.resume(); // receive the next value
    }
  }
}
