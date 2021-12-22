/* LucidTronix 7 Segment LED
 * and 74HC595 shift register
 * Tutorial at: 
 * http://www.lucidtronix.com/tutorials/41
 */
const int latchPin = 8;  //Pin connected to Pin 12 of 74HC595 (Latch)
const int dataPin  = 11;  //Pin connected to Pin 14 of 74HC595 (Data)
const int clockPin = 12;  //Pin connected to Pin 11 of 74HC595 (Clock)

byte dec_digits[] = {0b11000000,0b11111001,0b10100100,0b10110000,0b10011001,0b10010010,0b10000011,0b11111000,0b10000000,0b10011000 };

void setup() {
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  for (int numberToDisplay = 0; numberToDisplay < 10; numberToDisplay++) {
    // take the latchPin low so 
    // the LEDs don't change while you're sending in bits:
    digitalWrite(latchPin, LOW);
    // shift out the bits:
    shiftOut(dataPin, clockPin, MSBFIRST, dec_digits[numberToDisplay]); 
    //take the latch pin high so the LEDs will light up:
    digitalWrite(latchPin, HIGH);
    // pause before next value:
    delay(1000);
  }
}
