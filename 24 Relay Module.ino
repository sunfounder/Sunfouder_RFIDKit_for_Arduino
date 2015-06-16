/**********************************************/
const int relayPin =6; //the "s" of relay module attach to
/**********************************************/
void setup()
{
  pinMode(relayPin, OUTPUT); //initialize relay as an output
}
/***********************************************/
void loop()
{
  digitalWrite(relayPin, HIGH); //Close the relay
  delay(1000); //wait for 1 second
  digitalWrite(relayPin, LOW); //disconnect the relay 
  delay(1000); //wait for 1 second
}
/*************************************************/
