#include <IRremote.h>  
 
const int irReceiverPin = 2;  
const int ledPin = 13;
 
IRrecv irrecv(irReceiverPin); 
decode_results results;    
 
void setup()
{
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);   
  irrecv.enableIRIn();   
}
 
void loop() 
{
  if (irrecv.decode(&results)) {   
    Serial.print("irCode: ");            
    Serial.print(results.value, HEX); 
    Serial.print(",  bits: ");           
    Serial.println(results.bits); 
    irrecv.resume();    
  }  
  delay(600); 
  if(results.value == 0xFFA25D)
  {
    digitalWrite(ledPin,HIGH);
  }
  else
  {
    digitalWrite(ledPin,LOW);
  }
}
