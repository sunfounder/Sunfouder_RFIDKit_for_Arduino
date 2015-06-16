
// Project 6 - Interactive LED Chase Effect

int ledNum = 8; //the number of the led you attach
byte ledPin[] = {2, 3, 4, 5, 6, 7, 8, 9};    // Create array for LED pins
int ledDelay; // delay between changes
int direction = 1;
int currentLED = 0;
unsigned long changeTime;
int potPin = 0;    // select the input pin for the potentiometer

void setup() {
for (int x = 0; x < ledNum; x++)
  // set all pins to output
 { pinMode(ledPin[x], OUTPUT); }
    	changeTime = millis();
}

void loop() {
ledDelay = analogRead(potPin); // read the value from the pot 
if ((millis() - changeTime) > ledDelay) {      // if it has been ledDelay ms since last change
    		changeLED();
   		changeTime = millis();
  	}
}

void changeLED() {
    	for (int x=0; x < ledNum; x++) {   // turn off all LED's
    		digitalWrite(ledPin[x], LOW);
  	}
    	digitalWrite(ledPin[currentLED], HIGH); // turn on the current LED
currentLED += direction; // increment by the direction value
  	// change direction if we reach the end
 	 if (currentLED == ledNum-1) {direction = -1;}
  	if (currentLED == 0) {direction = 1;}
}
