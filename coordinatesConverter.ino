static float current[2] = {12.0, 5.0};
static float target[2] = {6.0, 7.0};

void setup()
{
  Serial.begin(9600);
  
  float cX = current[0];
  float cY = current[1];

  float tX = target[0];
  float tY = target[1];

  Serial.print("current coordinates: x=");
  Serial.print(cX);
  Serial.print(", y=");
  Serial.println(cY);

  Serial.print("current angle: ");
  Serial.print(GetAngle(cX, cY));
  Serial.println("˚");
  Serial.print("current distance: ");
  Serial.println(GetDistance(cX, cY));

  Serial.print("target coordinates: x=");
  Serial.print(tX);
  Serial.print(", y=");
  Serial.println(tY);

  Serial.print("target angle: ");
  Serial.print(GetAngle(tX, tY));
  Serial.println("˚");
  Serial.print("target distance: ");
  Serial.println(GetDistance(tX, tY));
}

void loop()
{
  
}

float GetAngle(float x, float y)
{
  float a = atan(y / x);
  a *= (180.0/3.1415);
  return a;
}

float GetDistance(int x, int y)
{
  float d = sqrt(pow(x, 2) + pow(y, 2));
  return d;
}
