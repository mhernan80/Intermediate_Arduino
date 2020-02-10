
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
	Serial.begin(9600);
	lcd.init();
	lcd.backlight();
	lcd.setCursor(0,0);
	lcd.print("Brightness");
}

void loop()
{
	int LED = analogRead(A3);
	analogWrite(6, LED/5);//divides the potentiometer value by five so the LED can use the value
	Serial.println(LED);
	delay(50);
	lcd.setCursor(0,12);//Sets the cursor to two spaces after "Brightness"
	lcd.print(round(LED/100));//divides the potentiometer value by 100 to make it a value between one and ten, then rounds it to the nearest whole number
	lcd.print(" ");//helps make sure that if it prints: -10, the zero isn't left behind the next time you print a normal 10
}

