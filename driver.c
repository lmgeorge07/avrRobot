/*
By: Levis George
Purpose: Simple Arduino robot programmed in C
Functionality: Drive forward, backward with wall-detection and avoidance
*/
#include <stdint.h>
#include <stdbool.h>
#include "avr_objects.h"
#include "sensor.h"
#include "motor.h"

// Global initialization of ports
volatile uint8_t* MCUCR = (uint8_t*) MCU_CR;
volatile io_port_t* portb = (io_port_t*) PORT_B;
volatile io_port_t* portd = (io_port_t*) PORT_D;

/* Entry point */
int main() {
  portb->ddr = PORT_B_DDR;  // Using pins 8 & 9 for wheels respectively, pin 10 for wall detection (1 if wall detected)
  portd->ddr = PORT_D_DDR; // Pin 7 is output (TRIG) & pin 6 is input (ECHO)

  // Local 8 bit timer
  volatile timer8_t* timer2 = (timer8_t*) TIMER_2;
  timer2->controlA = TIMER_MODE_NORMAL;
  timer2->controlB = TIMER2_PRESCALER_64;
  timer2->counter = 0;

  // Keep track of whether bot will reverse left or right (switching it up occasionally)
  void (*reverse_fxn)() = &reverse_right;

  // Main loop
  while(1) {
    // Move forward
    run();

    // If a wall is encountered, reverse left/right until wall is out of view
    while (wall_detected()) (*reverse_fxn)();

    // Vary reverse styles
    //reverse_fxn = (timer2->counter % 2 == 0) ? &reverse_right : &reverse_left;
  }
  return 0;
}
