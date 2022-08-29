#include <Servo.h> 

static float current[2] = {0.0, 0.0};

const int pinServo1 = 9;
const int pinServo2 = 10;
const int pinServo3 = 11;
const float armA = 80.0;
const float armB = 80.0;

float i = 1;

const byte x = A0;
const byte y = A1;

const int sw = 2;
const int xOffset = 505;
const int yOffset = 501;

float cX = current[0];
float cY = current[1];


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
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  
  pinMode(13, OUTPUT);
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  pinMode(sw, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop()
{
  int xVal = analogRead(x) - xOffset;
  if (xVal < -50) cX -= i;
  if (xVal > 50) cX += i;

  if (cX > 180) cX = 180;
  if (cX < -180) cX = -180;

  int yVal = analogRead(y) - yOffset;
  if (yVal < -50) cY -= i;
  if (yVal > 50) cY += i;

  if (cY > 180) cY = 180;
  if (cY < 0) cY = 0;


 // Serial.print(cX);
  //Serial.print(" ");
  //Serial.println(cY);
  servo1.write(GetAngle(cX, cY));

  
  float servo2deg3 = (2*GetDistance(cX, cY)*armB);

  float servo2deg0 = pow(GetDistance(cX, cY), 2)-pow(armA, 2)+pow(armB, 2);
  
  float servo2deg = (pow(GetDistance(cX, cY), 2)-pow(armA, 2)+pow(armB, 2))/(2*GetDistance(cX, cY)*armB);

  float servo2deg2 = acos(servo2deg);
//  Serial.print(analogRead(x));
  float servo3deg1 = GetDistance(cX, cY);
  float servo3deg2 = pow(armA, 2)+pow(armB, 2)-pow(servo3deg1, 2);
  float servo3deg3 = servo3deg2/(2*armA*armB);
  float servo3deg4 = acos(servo3deg3);
//  Serial.print("1: ");
//  Serial.println(servo3deg1);
//  Serial.print("2: ");
//   Serial.println(servo3deg2);
//   Serial.print("3: ");
//    Serial.println(servo3deg3);
//    Serial.print("4: ");
//     Serial.println(servo3deg4);
//     Serial.println(GetDistance(cX, cY));
  

 
  //Serial.print(servo2deg);
  //Serial.print(" ");
  Serial.println(servo3deg4);
  servo2.write(servo2deg2*180/3.1415926);
  servo3.write(servo3deg4*180/3.1415926);
  delay(8);
}

float GetAngle(float x, float y) {
  float a = atan(y / x); 
  a *= (180.0/3.1415);
  return a + 90;
}

float GetDistance(float x, float y) {
  float d = sqrt(pow(x, 2) + pow(y, 2));
  return d;
}
