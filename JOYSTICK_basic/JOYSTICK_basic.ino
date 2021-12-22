const byte PIN_ANALOG_X = 0;
const byte PIN_ANALOG_Y = 1; 

int x_position;
int y_position;

int x_direction;
int y_direction;

void setup() {
  Serial.begin(9600);
}

void loop () {
  x_direction = 0;
  y_direction = 0;
 
  x_position = analogRead(PIN_ANALOG_X);
  y_position = analogRead(PIN_ANALOG_Y);
 
 Serial.println("\nx_position : ");
 Serial.print(x_position);
 Serial.println("\ny_position : ");
 Serial.write(y_position);
 delay(2000); 
}
