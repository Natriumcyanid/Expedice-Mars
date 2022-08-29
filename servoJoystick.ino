#include <Servo.h> 
// pin defining
const int pinServo1 = 1;
const int pinServo2 = 2;
const int pinServo3 = 3;
const byte x = A0;
const byte y = A1;
const int sw = 2;

// X and Y axis offsets (makes the measured values 0 when you're not moving the joystick)
const int xOffset = 505;
const int yOffset = 501;

// Create servo objects
Servo servo1; // The servo that rotates the whole arm
Servo servo2; // The first limb
Servo servo3; // The second limb

void setup() {
  
  // Attach servo objects to Arduino pins
  servo1.attach(pinServo1);
  servo2.attach(pinServo2);
  servo3.attach(pinServo3);
  // Pin modes
  pinMode(13, OUTPUT);
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  pinMode(sw, INPUT_PULLUP);

  // Serial startup at 9600 baud
  Serial.begin(9600);
}

void loop() {
  // Fixing inaccuracy of x values
  int xVal = analogRead(x) - xOffset;
  if (xVal >= -1 && xVal <= 1) xVal = 0;
  // Fixing inaccuracy of y values
  int yVal = analogRead(y) - yOffset;
  if (yVal >= -1 && yVal <= 1) yVal = 0;

  // Printing "SWITCH PRESSED" to serial when switch is pressed
  if (digitalRead(sw) == LOW) Serial.println("SWITCH PRESSED");

  // Printing measured values to serial if they aren't 0
    if (xVal != 0) {
  Serial.print("x value: ");
  Serial.println(xVal);
  }
  if (yVal != 0) {
  Serial.print("y value: ");
  Serial.println(yVal);
  }
  
  // 8 ms delay
  delay(8);
}
