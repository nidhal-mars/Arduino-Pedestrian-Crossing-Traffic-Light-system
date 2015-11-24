
#include "Traffic_light.h"

/* configuration of Traffic light 1  */
#define MT_RED_LED_PIN1       4
#define MT_YELLOW_LED_PIN1    5
#define MT_GREEN_LED_PIN1     6
#define PT_RED_LED_PIN1       7
#define PT_GREEN_LED_PIN1     8
#define BUTTON_PIN1           2
/* configuration of Traffic light 2  */
#define MT_RED_LED_PIN2       9
#define MT_YELLOW_LED_PIN2   10
#define MT_GREEN_LED_PIN2    11
#define PT_RED_LED_PIN2      12
#define PT_GREEN_LED_PIN2    13
#define BUTTON_PIN2           3

Traffic traffic[2] ;   // Create Traffic instance.
Traffic_InitStructure initStructure; // Traffic init structure

/* Initialize */
void setup() {
  /* Configures Traffic light 1 Pins */
  initStructure.pin[MT_RED] = MT_RED_LED_PIN1 ;  // MT = Main Traffic
  initStructure.pin[MT_YELLOW] = MT_YELLOW_LED_PIN1 ;
  initStructure.pin[MT_GREEN] = MT_GREEN_LED_PIN1 ;
  initStructure.pin[PT_RED] = PT_RED_LED_PIN1 ; // PT = Pedestrian Traffic
  initStructure.pin[PT_GREEN] = PT_GREEN_LED_PIN1 ;
  initStructure.Btn_pin = BUTTON_PIN1 ;
  /* initialize Traffic Traffic light 2 Pins */
  traffic[0].init(initStructure);
  /* Configures MCU GPIO */
  initStructure.pin[MT_RED] = MT_RED_LED_PIN2 ;
  initStructure.pin[MT_YELLOW] = MT_YELLOW_LED_PIN2 ;
  initStructure.pin[MT_GREEN] = MT_GREEN_LED_PIN2 ;
  initStructure.pin[PT_RED] = PT_RED_LED_PIN2 ;
  initStructure.pin[PT_GREEN] = PT_GREEN_LED_PIN2 ;
  initStructure.Btn_pin = BUTTON_PIN2 ;
  /* initialize Traffic light 2 */
  traffic[1].init(initStructure);


  cli();//stop interrupts
  //set timer1 interrupt at 1Hz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS12 and CS10 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  sei();//allow interrupts

  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN1), interrupt1 , CHANGE); // Enable Button 1 interrupt
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN2), interrupt2 , CHANGE); // Enable Button 2 interrupt

}

/* button 1  interrupt  */
void interrupt1()
{ traffic[0].interrupt();}

/* button 2 interrupt  */
void interrupt2()
{ traffic[1].interrupt();}


/* update timer  */
ISR(TIMER1_COMPA_vect) { //timer1 interrupt 1Hz
traffic[0].updateTimer();
traffic[1].updateTimer();
}


/*  Main loop  */
void loop() {
  traffic[0].routine(); // state machine of Traffic light system 1
  traffic[1].routine(); // state machine of Traffic light system 2
}



