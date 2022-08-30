#include <Servo.h>

float X = 0;
float Y = 100;
float krok=300;

float potXval;
float potYval;
int lasttime;
bool pressed = true;

float arm1=130;
float arm2=113;
float stand = 50;

Servo servo1;  // create servo object to control a servo
Servo servo2;  // create servo object to control a servo
Servo servo3;  // create servo object to control a servo

// twelve servo objects can be created on most boards


void setup() {
  // put your setup code here, to run once:
  servo1.attach(9,1000,2000);  // attaches the servo on GIO2 to the servo object
  servo2.attach(10,1000,2000);  // attaches the servo on GIO2 to the servo object
  servo3.attach(11,1000,2000);  // attaches the servo on GIO2 to the servo object
  pinMode(A1,INPUT);
  pinMode(A0,INPUT);
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);

}

void loop() {
X += (analogRead(A1)-512) / 1000.0;
Y += (analogRead(A0)-512) / 1000.0;
float alpha = 0;
alpha = (atan(X/Y)*180) / 3,1415;
alpha += 90;
alpha = 180 - alpha;
Serial.println(digitalRead(2));
float length = 0;
length = sqrt(X*X + Y*Y + stand*stand);
//Serial.print(", ");
//Serial.print(length);
float beta = 0;
beta = length * length + arm1 * arm1 - arm2 * arm2;
beta /= 2 * length * arm1;
beta = acos(beta)*180/3,1415;
if (digitalRead(2) == LOW && millis() - lasttime > 1000)
{
  lasttime = millis();
  pressed = !pressed;
}
if (pressed)
{
  beta += 10;
}

//Serial.print(", ");
Serial.print(beta);
Serial.print(",");
Serial.print(alpha);
servo1.write((alpha - 30) * 3 / 2);
servo2.write((beta - 30) * 3 / 2);
float gamma = 0;
gamma = arm1*arm1 + arm2*arm2 - length * length;
gamma /= 2 * arm1 * arm2;
gamma = acos(gamma)*180/3,1415;
gamma = 180 - gamma;
Serial.print(", ");
Serial.println(gamma);
servo3.write((gamma - 30) * 3 / 2);

Serial.print(", ");
Serial.print(X);
Serial.print(", ");
Serial.println(Y);

delay(10);

}
