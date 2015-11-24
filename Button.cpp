#include "Button.h"

void Button::init(byte button_pin ) // init button 
{
Button_pin=button_pin;
pinMode(Button_pin, INPUT);
}

boolean Button::getState()  // get button state
{
state = digitalRead(Button_pin);
return state;
}

