#include <Servo.h> 
int servo1 = 1;
int servo2 = 2;
int servo3 = 3;

// Create servo objects
Servo servo1;
Servo servo2;
Servo servo3;

void setup() {
  // Attach servo objects to Arduino pins
  servo1.attach(servo1);
  servo2.attach(servo2);
  servo3.attach(servo3);
}

void loop() {
 
}
