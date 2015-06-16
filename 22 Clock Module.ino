#include <stdio.h>
#include <string.h>
#include <DS1302.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

uint8_t CE_PIN   = 5;  //RST pin attach to
uint8_t IO_PIN   = 6;  //
uint8_t SCLK_PIN = 7;
/* Create buffers */
char buf[50];
char day[10];
/* 串口数据缓存 */
String comdata = "";
int numdata[7] ={0}, j = 0, mark = 0;
/* Create a DS1302 object */
DS1302 rtc(CE_PIN, IO_PIN, SCLK_PIN);


void print_time()
{
    /* Get the current time and date from the chip */
    Time t = rtc.time();
    /* Name the day of the week */
    memset(day, 0, sizeof(day));
    switch (t.day)
    {
    case 1: strcpy(day, "Sun"); break;
    case 2: strcpy(day, "Mon"); break;
    case 3: strcpy(day, "Tue"); break;
    case 4: strcpy(day, "Wed"); break;
    case 5: strcpy(day, "Thu"); break;
    case 6: strcpy(day, "Fri"); break;
    case 7: strcpy(day, "Sat"); break;
    }
   /* Format the time and date and insert into the temporary buffer */
    snprintf(buf, sizeof(buf), "%s %04d-%02d-%02d %02d:%02d:%02d", day, t.yr, t.mon, t.date, t.hr, t.min, t.sec);
    /* Print the formatted string to serial so we can see the time */
    Serial.println(buf);
    lcd.setCursor(2,0);
    lcd.print(t.yr);
    lcd.print("-");
    lcd.print(t.mon/10);
    lcd.print(t.mon%10);
    lcd.print("-");
    lcd.print(t.date/10);
    lcd.print(t.date%10);
    lcd.print(" ");
    lcd.print(day);
    lcd.setCursor(4,1);
    lcd.print(t.hr);
    lcd.print(":");
    lcd.print(t.min/10);
    lcd.print(t.min%10);
    lcd.print(":");
    lcd.print(t.sec/10);
    lcd.print(t.sec%10);
}


void setup()
{
    Serial.begin(9600);
    //rtc.hour(0);//24-hour mode
    rtc.hour(128);//12-hour mode
    rtc.write_protect(false);
    rtc.halt(false);
    lcd.init();  //initialize the lcd
  lcd.backlight();  //open the backlight 
 Time t(2009, 5, 19, 21, 16, 37, 3);
  /* Set the time and date on the chip */
  rtc.time(t);
}

void loop()
{

    /* 当串口有数据的时候，将数据拼接到变量comdata */
    while (Serial.available() > 0)
    {
        comdata += char(Serial.read());
        delay(2);
        mark = 1;
    }
    /* 以逗号分隔分解comdata的字符串，分解结果变成转换成数字到numdata[]数组 */
    if(mark == 1)
    {
        Serial.print("You inputed : ");
        Serial.println(comdata);
        for(int i = 0; i < comdata.length() ; i++)
        {
            if(comdata[i] == ',' || comdata[i] == 0x10 || comdata[i] == 0x13)
            {
                j++;
            }
            else
            {
                numdata[j] = numdata[j] * 10 + (comdata[i] - '0');
            }
        }
        /* 将转换好的numdata凑成时间格式，写入DS1302 */
        Time t(numdata[0], numdata[1], numdata[2], numdata[3], numdata[4], numdata[5], numdata[6]);
        rtc.time(t);
        mark = 0;j=0;
        /* 清空 comdata 变量，以便等待下一次输入 */
        comdata = String("");
        /* 清空 numdata */
        for(int i = 0; i < 7 ; i++) numdata[i]=0;
    }
    
    /* 打印当前时间 */
    print_time();
    delay(1000);
}
