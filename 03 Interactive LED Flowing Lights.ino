
// Project 6 - Interactive LED Chase Effect

int ledNum = 8; //the number of the led you attach
byte ledPin[] = {2, 3, 4, 5, 6, 7, 8, 9};    // Create array for LED pins
int ledDelay; // delay between changes
int potPin=A0;

void setup() {
  for (int x = 0; x < ledNum; x++)
  { 
    pinMode(ledPin[x], OUTPUT); 
  
  }	
}

void loop() {
  for(int i=0;i<8;i++)
  {
    ledDelay = analogRead(potPin);
    digitalWrite(ledPin[i],HIGH);
    delay(ledDelay);
    digitalWrite(ledPin[i],LOW);
  }

  for(int i=7;i>=0;i--)
  {
    ledDelay = analogRead(potPin);
    digitalWrite(ledPin[i],HIGH);
    delay(ledDelay);
    digitalWrite(ledPin[i],LOW);
  }
}

