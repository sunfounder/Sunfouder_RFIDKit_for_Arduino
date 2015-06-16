#include <SPI.h>
#include <RFID.h>
#include <LiquidCrystal.h>

#define SS_PIN 10
#define RST_PIN 9

#define relayPin 8

RFID rfid(SS_PIN, RST_PIN);

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// Setup variables:
int serNum0;
int serNum1;
int serNum2;
int serNum3;
int serNum4;

void setup()
{ 
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  lcd.begin(16, 2);
  SPI.begin(); 
  rfid.init(); 
 lcd.setCursor(0,0);
 lcd.print(" Access Control "); 
}

void loop()
{ 
  if (rfid.isCard()) 
  {
    if (rfid.readCardSerial()) 
    {
      if(rfid.serNum[0] == 21 && rfid.serNum[1] == 111 && rfid.serNum[2] == 159 && rfid.serNum[3] == 175 && rfid.serNum[4] == 74)
      {
        lcd.setCursor(0,1);
        lcd.print("Hello SUNFOUNDER");
        digitalWrite(relayPin, HIGH);
        delay(1000);
      }
      else 
      {
        /* If we have the same ID, just write a dot. */
        lcd.setCursor(0,1);
        lcd.print("                 ");
        lcd.setCursor(0,1);
        lcd.print("Hello unkown guy!");
        digitalWrite(relayPin, LOW);
        delay(1000);
      }
    }
  }
  lcd.setCursor(0,1);
  lcd.print("                 ");
  digitalWrite(relayPin, LOW);
  rfid.halt();
}
