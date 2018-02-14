#include "sensor.h"

/*
Params:
port - io_port_t** - pass in address of initialized port (connected to the sensor)
trigger - uint8_t - pass in trigger address (ie. digital pin 7 -> 0x80 (bit 7 will be set high for trigger))
echo - uint8_t - pass in echo address (ie. digital pin 6 -> 0x40 (bit 6 will be read for echo))
*/
bool wall_detected () {
  // Initialize 16 bit timer
  //volatile uint8_t* timer1_if = (uint8_t*) 0x0036;
  volatile timer16_t* timer1 = (timer16_t*) TIMER_1;
  timer1->controlA = TIMER_MODE_NORMAL;  // Normal mode
  timer1->controlB = TIMER_PRESCALER_64;  // prescaler/64
  timer1->counter = 0;
  //*timer1_if = 1;  // Clear any prior flags

  // Sensor triggered by high pulse (Giving low pulse for 10us first)
  portd->data = 0x00;
  delay_in_10us(1);
  portd->data = PORT_D_TRIGGER;
  delay_in_10us(1);
  portd->data = 0x00;

  // Wait until high pulse begins
  while (((portd->in) & PORT_D_ECHO) != PORT_D_ECHO);

  // Wait until high pulse ends (response received)
  // If response taking too long (timer counter overflowed) exit
  while (((portd->in) & PORT_D_ECHO) != 0x00) {
    //if (timer1->counter > 8092) return false;
    //  if ((*timer1_if & 0x01) == 0x01) return false;
  }

  return (timer1->counter < STOP_COUNTER_TIME);  // Check time passed & return

}
