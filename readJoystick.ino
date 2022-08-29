const byte x = A0;
const byte y = A1;
const int sw = 2;

const int xOffset = 505;
const int yOffset = 501;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  pinMode(sw, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  
  int xVal = analogRead(x) - xOffset;
  if (xVal >= -1 && xVal <= 1) xVal = 0;

  int yVal = analogRead(y) - yOffset;
  if (yVal >= -1 && yVal <= 1) yVal = 0;

  if (digitalRead(sw) == LOW) Serial.println("SWITCH PRESSED");

  Serial.print("x value: ");
  Serial.println(xVal);

  Serial.print("y value: ");
  Serial.println(yVal);
  
  delay(8);
}
