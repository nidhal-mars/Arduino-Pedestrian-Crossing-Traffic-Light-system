#ifndef Led_h
#define Led_h

#include <Arduino.h>

enum Led_state {OFF , ON }; // led state 

class Led {
public:
	void init(byte led_pin); // initialize led
	void switch_ON(); // turn led on 
	void switch_OFF(); // turn led off
	
private:
	byte 		LedPin;  // led pin 
	Led_state 	state; // led state 
};

#endif
