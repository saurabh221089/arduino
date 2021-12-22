#include <IRremote.h>
int RECV_PIN = 11; //define input pin on Arduino
IRrecv irrecv(RECV_PIN);
decode_results results;
int redpin = 6;    // select the input pin for the potentiometer
int bluepin =3;      // select the pin for the LED
int greenpin =5;
int ledpin =9;

void setup()
{
Serial.begin(9600);
irrecv.enableIRIn(); // Start the receiver
}

void loop() {
if (irrecv.decode(&results)) {
  //Serial.println(results.value);
  switch (results.value)  {
      case 4178649581:
        Serial.println("Power");
        digitalWrite(ledpin, HIGH);
        break;
      case 3255675471:
        Serial.println("Vol+");
        break;
      case 1299073225:
        Serial.println("Vol-");
        break;
      case 1253111734:
        Serial.println("Button Pressed");
        break;
      case 2545676015:
        digitalWrite(redpin, HIGH);
        digitalWrite(bluepin, LOW);
        digitalWrite(greenpin, LOW);
        Serial.println("DGT1");
        break;
      case 154895949:
        digitalWrite(bluepin, HIGH);
        digitalWrite(redpin, LOW);
        digitalWrite(greenpin, LOW);
        Serial.println("DGT2");
        break;
      case 2267322763:
        digitalWrite(greenpin, HIGH);
        digitalWrite(redpin, LOW);
        digitalWrite(bluepin, LOW);
        Serial.println("DGT3");
        break;
      case 1017028645:
        Serial.println("DGT4");
        break;
      case 1228829163:
        Serial.println("DGT5");
        break;
      case 4138496137:
        Serial.println("DGT6");
        break;
      case 1420736847:
        Serial.println("DGT7");
        break;
      case 3519705101:
        Serial.println("DGT8");
        break;
      case 3656716803:
        Serial.println("DGT9");
        break;
     }
  irrecv.resume(); // Receive the next value
}
}
