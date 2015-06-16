
const int photocellPin = A0;  //photocell attach to
int sensorValue = 0;        // value read from the sensor
const int buzzerPin = 9;  //buzzer attach to

void setup()
{
  pinMode(buzzerPin, OUTPUT);  //initialize buzzer as an output
}
void loop()
{
  sensorValue = analogRead(photocellPin); 
  digitalWrite(buzzerPin, HIGH);
  delay(sensorValue);  //wait for a while,and the delay time depend on the sensorValue
  digitalWrite(buzzerPin, LOW);
  delay(sensorValue);
}
