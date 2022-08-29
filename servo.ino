#include <Servo.h> 
const int pinServo1 = 1;
const int pinServo2 = 2;
const int pinServo3 = 3;

// Create servo objects
Servo servo1; // The servo that rotates the whole arm
Servo servo2; // The first limb
Servo servo3; // The second limb

void setup() {
  // Attach servo objects to Arduino pins
  servo1.attach(pinServo1);
  servo2.attach(pinServo2);
  servo3.attach(pinServo3);
}

void loop() {
 
}
