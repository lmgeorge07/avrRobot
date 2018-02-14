#ifndef MOTOR_H
#define MOTOR_H
#include <stdint.h>
#include "avr_objects.h"
#include "delay.h"

// Delays for proper dc motor speed (clockwise/counterclockwise)
#define MOTOR_PERIOD_MS 20
#define MOTOR_STOP 120
#define MOTOR_CW_1 130
#define MOTOR_CW_2 140
#define MOTOR_CW_3 150
#define MOTOR_CCW_1 100
#define MOTOR_CCW_2 90
#define MOTOR_CCW_3 80

extern volatile io_port_t* portb;  // Initialized in driver.c

void run();
void stop();
void reverse_left();
void reverse_right();

#endif  // MOTOR_H
