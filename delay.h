#ifndef DELAY_H
#define DELAY_H
#include <stdint.h>
#include "avr_objects.h"

void delay_10us();  // Delay for 10 us
void delay_1ms();  // Delay for 1 ms
void delay_in_10us(uint32_t);  // Delay for 10 us x amount of times
void delay_in_ms(uint32_t);  // Delay for 1 ms x amount of times

#endif  // DELAY_H
