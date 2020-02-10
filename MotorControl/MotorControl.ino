#include <Arduino.h>

int pin = 6;
int potent = 0;

void setup()
{
	Serial.begin(9600);
	pinMode(pin, OUTPUT);
}


void loop()
{
	potent = analogRead(A1)/4;//makes the potentiometer value lower so that it is easier on the motor
	delay(50);
	analogWrite(pin, 0);//prints the potentiometer value to the motor
}
