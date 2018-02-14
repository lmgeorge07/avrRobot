#ifndef SENSOR_H
#define SENSOR_H
#include <stdint.h>
#include <stdbool.h>
#include "avr_objects.h"
#include "delay.h"

#define STOP_COUNTER_TIME 600  // Timer counter difference when "wall detected"

extern volatile io_port_t* portd;

bool wall_detected();  // Returns true if within 3 inches of a wall

#endif  // SENSOR_H
