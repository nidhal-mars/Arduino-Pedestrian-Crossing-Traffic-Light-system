#include "Traffic_light.h"

void Traffic::init(Traffic_InitStructure initStructure) // initialize the system
{
  for (byte i = 0 ; i < 5 ; i++)
    led[i].init(initStructure.pin[i]);
  btn.init(initStructure.Btn_pin);
  state = NORMAL_MODE;
}

void Traffic::updateTimer()
{
if (timer) // if the counter is charged ==> decrement it
timer--;  
}

void Traffic::routine() // state machine of the traffic system 
{
  switch (state)
  {
    case NORMAL_MODE :
      switch (subState1)
      {
        case 0 : // turn Yellow led of main traffic ON
          led[MT_RED].switch_OFF();
          led[MT_YELLOW].switch_ON();
          led[MT_GREEN].switch_OFF();
          timer = TIME_TO_CHANGE_LIGHT; // load timer to Wait "TIME_TO_CHANGE_LIGHT"
          subState1++;
          break;
        case 1 : // Wait TIME_TO_CHANGE_LIGHT
          if (!timer)
            subState1++;
          break;
        case 2 : // turn GREEN led of main traffic ON
          led[MT_RED].switch_OFF();
          led[MT_YELLOW].switch_OFF();
          led[MT_GREEN].switch_ON();
          led[PT_RED].switch_ON();
          led[PT_GREEN].switch_OFF();
          break;
      }
      break;
    case PEDESTRIAN_MODE :
      switch (subState2)
      { case 0 : // turn Yellow led of main traffic ON
          led[MT_RED].switch_OFF();
          led[MT_YELLOW].switch_ON();
          led[MT_GREEN].switch_OFF();
          timer = TIME_TO_CHANGE_LIGHT; // load timer to Wait "TIME_TO_CHANGE_LIGHT"
          subState2++;
          break;
        case 1 : // Wait TIME_TO_CHANGE_LIGHT
          if (!timer)
            subState2++;
          break;
        case 2 : // turn red led of main traffic ON and  turn green led of pedestrian traffic ON
          led[MT_RED].switch_ON();
          led[MT_YELLOW].switch_OFF();
          led[MT_GREEN].switch_OFF();
          led[PT_RED].switch_OFF();
          led[PT_GREEN].switch_ON();
          timer = TIME_TO_CROSS_THE_STREET; // load timer "TIME_TO_CROSS_THE_STREET"
          subState2++;
          break;
        case 3 : // Wait until the pedestrian cross the street and turn red led of pedestrian traffic ON
          if (!timer)
          { subState2 = 0;
            state = NORMAL_MODE;
            led[PT_RED].switch_ON();
            led[PT_GREEN].switch_OFF();
            subState1 = 0;
          }
          break;
      }
      break;
  }
}

void Traffic::interrupt()  // called when the Pedestrian button is clicked
{
  state = PEDESTRIAN_MODE;
}
