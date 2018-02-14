#include "delay.h"

void delay_10us() {
  volatile uint8_t* timer0_interrupt_flag=(uint8_t *) TIMER_0_IF;
  volatile timer8_t* timer0 = (timer8_t*) TIMER_0;
  timer0->controlA = TIMER_MODE_NORMAL;
  timer0->controlB = TIMER_PRESCALER_64;
  timer0->counter = 254;
  *timer0_interrupt_flag = 1;  // Clearing flag

  // Once overflow occurs, it has been 10us
  while((*timer0_interrupt_flag & 0x01 ) == 0);
}

void delay_1ms() {
  volatile timer8_t* timer0 = (timer8_t*) TIMER_0;
  uint8_t previousCounterValue = 6;
  timer0->controlA = TIMER_MODE_NORMAL;
  timer0->controlB = TIMER_PRESCALER_8;
  timer0->counter = 6;
  while(1) {  // Overflow without interrupt flag check
    if(timer0->counter < previousCounterValue) break;
    previousCounterValue = timer0->counter;
  }
}

/*
Params:
x - uint32_t - Number of times to call delay_10us() fxn
*/
void delay_in_10us(uint32_t x) {
  uint32_t i;
  for (i = 0; i < x; ++i) delay_10us();
}

/*
Params:
x - uint32_t - Number of times to call delay_1ms() fxn
*/
void delay_in_ms(uint32_t x) {
  uint32_t i;
  for (i = 0; i < x; ++i) delay_1ms();
}
