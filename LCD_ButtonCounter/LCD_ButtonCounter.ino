#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);
boolean on_off = 0;//the variable to check if it was just pressed
int counter = 0;//times the button was pressed
void setup()
{
	lcd.init();
	lcd.backlight();
	lcd.setCursor(0,0);
	lcd.print("Press Counter:");
}

void loop()
{
	if(on_off == 0&&digitalRead(6)==1){//if the button is pressed and it previously wasn't pressed
		on_off = 1;//set it so it knows that the button was just on
		counter++;
		lcd.setCursor(0,1);
		lcd.print(counter);
	}
	if(on_off == 1&&digitalRead(6)==0){//if the button isn't on and it was just on
		on_off = 0;//set it so it knows it is off and it is ready to be re-added to
	}
}

