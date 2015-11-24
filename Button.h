#ifndef BUTTON_h
#define BUTTON_h

#include <Arduino.h>


class Button {
public:
  void init(byte button_pin ); // init button 
  boolean getState();   // get button state
  
private:
  byte    Button_pin; // button pin
  boolean   state;  // button state
};

#endif
