
#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,16,2);


#define relayPin 13


const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','4'},
  {'5','6','7','8'},
  {'9','A','B','C'},
  {'D','*','0','#'}
};
byte rowPins[ROWS] = {11, 10, 9, 8}; //connect to the row pinouts of the keypad
byte colPins[COLS] = { 7, 6, 5, 4}; //connect to the column pinouts of the keypad


int pos = 0;
char secretCode[6] = {'1', '2', '3', '4', '5', '6'};
char inputCode[6] = {'0', '0', '0', '0', '0', '0'};

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup()
{
  lcd.init();
  lcd.backlight();
  pinMode(relayPin, OUTPUT);
  //Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("    Welcome!    ");
  delay(2000);
}

void loop()
{
  readKey();
}

void readKey()
{
  int correct = 0;
  int i;
  char customKey = customKeypad.getKey();
  if (customKey)
  {
    switch(customKey)
    {
      case '*':
        pos = 0;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Input Your Code:");
      break;
      case '#':    
        for(i = 0; i < 6; i++)
        {
          if(inputCode[i] == secretCode[i])
          {
            correct ++;
          }
        }
        if(correct == 6)
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Input correctly!");
          lcd.setCursor(0, 1);
          lcd.print(" Please Come In ");
          digitalWrite(relayPin, HIGH);
          delay(2000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("    Welcome!    ");
          digitalWrite(relayPin, LOW);
        }
        else
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("  Input Error!  ");
          lcd.setCursor(0, 1);
          lcd.print("  Please Again  ");
          digitalWrite(relayPin, LOW);
          delay(2000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("    Welcome!    ");
        }
      break;
      default:
        inputCode[pos] = customKey;
        lcd.setCursor(pos,1);
        lcd.print(inputCode[pos]);
        pos ++;
    }
  }
}
