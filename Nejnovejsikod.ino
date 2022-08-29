#include <Servo.h> 

static float current[2] = {0.0, 0.0};


const int pinServo1 = 9;
const int pinServo2 = 10;
const int pinServo3 = 11;
const int armA = 10;
const int armB = 10;

const byte x = A0;
const byte y = A1;

const int sw = 2;
const int xOffset = 505;
const int yOffset = 501;

int dX = 0;
int dY = 0;

float cX = current[0];
float cY = current[1];
float oldAngle;


// Create servo objects
Servo servo1; // The servo that rotates the whole arm
Servo servo2; // The first limb
Servo servo3; // The second limb

void setup() {  
  // Attach servo objects to Arduino pins
  servo1.attach(pinServo1);
  servo2.attach(pinServo2);
  servo3.attach(pinServo3);

  // Reset servos
  servo1.write(180);
  servo2.write(180);
  servo3.write(180);
  
  pinMode(13, OUTPUT);
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  pinMode(sw, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop()
{
  int xVal = analogRead(x) - xOffset;
  if (xVal >= -1 && xVal <= 1) xVal = 0;

  int yVal = analogRead(y) - yOffset;
  if (yVal >= -1 && yVal <= 1) yVal = 0;

  float newAngle = GetAngle(xVal, yVal);
  servo1.write(GetAngle(xVal, yVal));
  servo2.write((asin((armB/armA)*sin((acos((pow(GetDistance(xVal, yVal), 2)-pow(armA, 2)-pow(armB, 2))/(-2*armA*armB)))))));
  servo3.write(acos((pow(GetDistance(xVal, yVal), 2)-pow(armA, 2)-pow(armB, 2))/(-2*armA*armB)));
  delay(100);
  Serial.println(xVal, yVal);
  Serial.println((asin((armB/armA)*sin((acos((pow(GetDistance(xVal, yVal), 2)-pow(armA, 2)-pow(armB, 2))/(-2*armA*armB)))))));
  Serial.println(acos((pow(GetDistance(xVal, yVal), 2)-pow(armA, 2)-pow(armB, 2))/(-2*armA*armB)));
  float oldAngle = newAngle;

  delay(5);
}

float GetAngle(float x, float y) {
  float a = atan(y / x);
  a *= (180.0/3.1415);
  return a;
}

float GetDistance(int x, int y) {
  float d = sqrt(pow(x, 2) + pow(y, 2));
  return d;
}

//void rotate() {
//(GetAngle(cX, cY));
 //(asin((armB/armA)*sin((acos((pow(GetDistance(xVal, yVal), 2)-pow(armA, 2)-pow(armB, 2))/(-2*armA*armB))))));
//GetDistance(xVal, yVal), 2)-pow(armA, 2)-pow(armB, 2))/(-2*armA*armB)));
