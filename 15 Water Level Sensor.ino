
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const int waterSensor = 0;
int waterValue = 0;

void setup()
{
  lcd.init();  //initialize the lcd
  lcd.backlight();  //open the backlight
  lcd.setCursor(0,0);
  lcd.print("  Water Sensor  ");
}

void loop()
{
    int waterValue = analogRead(waterSensor); // get water sensor value
    lcd.setCursor(6,1);
    lcd.print(waterValue);  //value displayed on lcd
    delay(200);
    lcd.setCursor(0,1);
    lcd.print("                ");
}
