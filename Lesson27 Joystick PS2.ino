const int xPin = A0;
const int yPin = A1;
const int swPin = 8;

void setup()
{
	pinMode(swPin,INPUT);
  digitalWrite(swPin, HIGH);
	Serial.begin(9600);
}

void loop()
{
	Serial.print("X: ");
	Serial.print(analogRead(xPin),DEC);
	Serial.print("|Y: ");
	Serial.print(analogRead(yPin),DEC);
	Serial.print("|Z: ");
	Serial.println(digitalRead(swPin));
	delay(500);
}
