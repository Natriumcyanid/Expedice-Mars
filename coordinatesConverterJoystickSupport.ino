static float current[2] = {0.0, 0.0};
static float target[2] = {6.0, 7.0};

const byte x = A0;
const byte y = A1;
const int sw = 2;

const int xOffset = 505;
const int yOffset = 501;

int dX = 0;
int dY = 0;

float cX = current[0];
float cY = current[1];

float tX = target[0];
float tY = target[1];

void setup()
{  
  Serial.begin(9600);

  pinMode(13, OUTPUT);
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  pinMode(sw, INPUT_PULLUP);
}

void loop()
{
  dX = 0;
  int xVal = analogRead(x) - xOffset;
  if (xVal > 50) dX = 1;
  if (xVal < -50) dY = -1;

  dY = 0;
  int yVal = analogRead(y) - yOffset;
  if (yVal > 50) dY = 1;
  if (yVal < -50) dY = -1;

  cX += dX;
  cY += dY;

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

  Serial.println();

  delay(3000  );
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
