#include "Led.h"

void Led::init(byte led_pin) // init led
{
LedPin=led_pin;
pinMode(LedPin, OUTPUT);
}

void Led::switch_ON() // turn led on 
{
digitalWrite(LedPin, HIGH);
state=ON;
}

void Led::switch_OFF() // turn led off
{
digitalWrite(LedPin, LOW);
state=OFF;
}

