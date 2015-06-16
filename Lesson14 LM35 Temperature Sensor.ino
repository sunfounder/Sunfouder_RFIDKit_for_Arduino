
//LM35 output voltage has a linear relation with the Celsius temperature, output of 0 v when 0 ℃, 
//every increase 1 ℃, the output voltage increase 10 mv
#define lmPin A0  //LM35 attach to
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

float tem = 0;
long lmVal = 0;

void setup()
{
  lcd.init();  //initialize the lcd
  lcd.backlight();  //open the backlight 
}
void loop()
{
  lmVal = analogRead(lmPin);
  tem = (lmVal * 0.0048828125 * 100);//5/1024=0.0048828125;1000/10=100
  lcd.setCursor(5,0);
  lcd.print("LM35");
  lcd.setCursor(0,1);
  lcd.print("Tem= ");
  lcd.setCursor(5,1);
  lcd.print(tem);
  lcd.print(" C");
  delay(200);
}
