#ifndef Traffic_h
#define Traffic_h

#include <Arduino.h>
#include "Led.h"
#include "Button.h"

#define TIME_TO_CHANGE_LIGHT 2
#define TIME_TO_CROSS_THE_STREET 5

typedef enum Traffic_state 
{ NORMAL_MODE,  // normal traffic mode 
  PEDESTRIAN_MODE,  // if a PEDESTRIAN click the buuton 
};

enum Led_Traffic_type
{ MT_RED, // Main traffic red led
  MT_YELLOW,  // Main traffic yellow led
  MT_GREEN, // Main traffic green led
  PT_RED, // PEDESTRIAN traffic red led
  PT_GREEN, // PEDESTRIAN traffic green led
};

typedef struct 
{
byte pin[5]; // main road traffic {RED,YELLOW,GREEN} pedestrian traffic {RED,GREEN}
byte Btn_pin; 
} Traffic_InitStructure ;  // structure used to initialize the system

class Traffic {
public:
  void init(Traffic_InitStructure initStructure);
  void routine();
  void interrupt(); // interruption : called when a Pedestrian click the button  
  void updateTimer(); // update Timer
volatile int timer ;

private:
  byte subState1 = 2 , subState2 = 0 ;
  Led  led[5];
  Button btn ;
  Traffic_state state; 

};
#endif
