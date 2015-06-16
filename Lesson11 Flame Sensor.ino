
const int analogInPin = A0;
const int digitalInPin = 8;
const int ledPin = 13;

void setup()
{
  pinMode(digitalInPin,INPUT);
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int analogVal = analogRead(analogInPin);
  Serial.println(analogVal);
  boolean stat = digitalRead(digitalInPin);

  if(stat == HIGH)
  { 
    digitalWrite(ledPin,HIGH);
  }
  else
  {
    digitalWrite(ledPin,LOW);
  } 
}
