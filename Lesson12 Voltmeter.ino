
// include the library code
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
/****************************************************/
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
float val = 0;
/****************************************************/
void setup()
{
  Serial.begin(9600);
  lcd.init();  //initialize the lcd
  lcd.backlight();  //open the backlight 
  lcd.print("Voltage Value:");
}
/****************************************************/
void loop()
{
  val = analogRead(A0);
  val = 0.5*val + 0.5*analogRead(A0);
  val = val/1024*5.0;
  Serial.print(val);
  Serial.print("V");
  Serial.println();
  lcd.setCursor(6,1);
  lcd.print(val);
  lcd.print("V");
  delay(200);
}
