/*********************************************/
const int ledPin = 13;//the number of the led pin
const int buttonPin = 8; //the button pin attach to
int val = 0;//variable to store the value read from button
/*********************************************/
void setup()
{
  pinMode(ledPin,OUTPUT);//initialize the ledPin as an output
  pinMode(buttonPin,INPUT);//initialize the buttonPin as an intput
}
/*********************************************/
void loop()
{
  val = digitalRead(buttonPin);//read the value from button
  if(val == HIGH)
  {
    digitalWrite(ledPin,LOW);//turn the led off
  }
  else //when pressed
  {
    digitalWrite(ledPin,HIGH);//turn the led on
  }
}
/***********************************************/

