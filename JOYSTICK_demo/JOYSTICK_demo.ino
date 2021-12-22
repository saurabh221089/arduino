const byte PIN_ANALOG_X = 1;
const byte PIN_ANALOG_Y = 2;

const int X_THRESHOLD_LOW = 505;
const int X_THRESHOLD_HIGH = 515;    

const int Y_THRESHOLD_LOW = 500;
const int Y_THRESHOLD_HIGH = 510;    

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
 
 
  if (x_position > X_THRESHOLD_HIGH) {
    x_direction = 1;
  } else if (x_position < X_THRESHOLD_LOW) {
    x_direction = -1;
  }

  if (y_position > Y_THRESHOLD_HIGH) {
    y_direction = 1;
  } else if (y_position < Y_THRESHOLD_LOW) {
    y_direction = -1;
  }
   
 
  if (x_direction == -1) {
      if (y_direction == -1) {
        Serial.println("left-down");
      } else if (y_direction == 0) {
        Serial.println("left");
      } else {
        // y_direction == 1
        Serial.println("left-up");      
      }  
  } else if (x_direction == 0) {
      if (y_direction == -1) {
        Serial.println("down");
      } else if (y_direction == 0) {
        Serial.println("centered");
      } else {
        // y_direction == 1
        Serial.println("up");      
      }
  } else {
      // x_direction == 1
      if (y_direction == -1) {
        Serial.println("right-down");
      } else if (y_direction == 0) {
        Serial.println("right");
      } else {
        // y_direction == 1
        Serial.println("right-up");      
      }
  }
}
