#include <IRremote.h>

int RECV_PIN = 6;

int red = 2;                 
int green = 4;                
int blue = 5;                

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(red, OUTPUT);      // sets the digital pin as output
  pinMode(green, OUTPUT);      // sets the digital pin as output
  pinMode(blue, OUTPUT);  // sets the digital pin as output
  digitalWrite(blue, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(red, HIGH);
}

void loop() {
  if (irrecv.decode(&results)) {
    
    //long int decCode = results.value;
    //Serial.println(decCode);
    switch (results.value) {
      case 2545676015:
        Serial.println("Red LED");
        digitalWrite(red, LOW);
        digitalWrite(green, HIGH);
        digitalWrite(blue, HIGH);
        break;
      case 154895949:
        Serial.println("Green LED");
        digitalWrite(green, LOW);
        digitalWrite(red, HIGH);
        digitalWrite(blue, HIGH);
        break;
      case 2267322763:
        Serial.println("Blue LED");
        digitalWrite(blue, LOW);
        digitalWrite(green, HIGH);
        digitalWrite(red, HIGH);
        break;
      case 1017028645:
        Serial.println("White LED");
        digitalWrite(blue, LOW);
        digitalWrite(green, LOW);
        digitalWrite(red, LOW);
        break;
      default: 
        Serial.println("Waiting to press a button...");
        digitalWrite(blue, HIGH);
        digitalWrite(green, HIGH);
        digitalWrite(red, HIGH);
    }

    irrecv.resume(); // Receive the next value
  }
}

