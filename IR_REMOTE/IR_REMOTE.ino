#include <IRremote.h>
int RECV_PIN = 6; //define input pin on Arduino(PWM PIN)
IRrecv irrecv(RECV_PIN);
decode_results results;
int digit = 0;

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
        digit=73;
        break;
      case 3255675471:
        Serial.println("Vol+");
        digit=0;
        break;
      case 1299073225:
        Serial.println("Vol-");
        digit=0;
        break;
      case 1253111734:
        Serial.println("Button Pressed");
        digit=0;
        break;
      case 1380417895:
        Serial.println("DGT0");
        digit=63;
        break;
      case 2545676015:
        Serial.println("DGT1");
        digit=6;
        break;
      case 154895949:
        Serial.println("DGT2");
        digit=91;
        break;
      case 2267322763:
        Serial.println("DGT3");
        digit=79;
        break;
      case 1017028645:
        Serial.println("DGT4");
        digit=102;
        break;
      case 1228829163:
        Serial.println("DGT5");
        digit=109;
        break;
      case 4138496137:
        Serial.println("DGT6");
        digit=125;
        break;
      case 1420736847:
        Serial.println("DGT7");
        digit=7;
        break;
      case 3519705101:
        Serial.println("DGT8");
        digit=127;
        break;
      case 3656716803:
        Serial.println("DGT9");
        digit=111;
        break;
     }
  irrecv.resume(); // Receive the next value
}
}
