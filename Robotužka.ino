#include <Servo.h> 
const int servo1 = 1;
const int servo2 = 2;
const int servo3 = 3;

// Create servo objects
Servo servo1; // The servo that rotates the whole arm
Servo servo2; // The first limb
Servo servo3; // The second limb

void setup() {
  // Attach servo objects to Arduino pins
  servo1.attach(servo1);
  servo2.attach(servo2);
  servo3.attach(servo3);
}

void loop() {
 
}
