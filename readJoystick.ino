// pin defining
const byte x = A0;
const byte y = A1;
const int sw = 2;

// x and y axis offsets (makes the measured values 0 when you're not moving the joystick)
const int xOffset = 505;
const int yOffset = 501;

void setup() {
  
  // pinmodes
  pinMode(13, OUTPUT);
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  pinMode(sw, INPUT_PULLUP);

  // serial startup at 9600 baud
  Serial.begin(9600);
}

void loop() {
  
  // fixing inaccuracy of x values
  int xVal = analogRead(x) - xOffset;
  if (xVal >= -1 && xVal <= 1) xVal = 0;

  // fixing inaccuracy of y values
  int yVal = analogRead(y) - yOffset;
  if (yVal >= -1 && yVal <= 1) yVal = 0;

  // printing "SWITCH PRESSED" to serial when switch is pressed
  if (digitalRead(sw) == LOW) Serial.println("SWITCH PRESSED");

  // printing measured values to serial if they aren't 0
    if (xVal != 0) {
  Serial.print("x value: ");
  Serial.println(xVal);
  }

  if (yVal != 0) {
  Serial.print("y value: ");
  Serial.println(yVal);
  }
  
  // 8ms delay
  delay(8);
}
