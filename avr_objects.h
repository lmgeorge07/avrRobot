#ifndef AVR_OBJECTS_H
#define AVR_OBJECTS_H

// Reg addresses
#define MCU_CR 0x0055  // mcu control register
#define PORT_B 0x0023  // portb->in
#define PORT_D 0x0029  // portd->in
#define TIMER_0 0x0044  // timer0->crA
#define TIMER_0_IF 0x0035  // timer0->interrupt_flag
#define TIMER_1 0x0080  //timer1->crA
#define TIMER_2 0x00B0  // timer2->crA

// Timer defaults
#define TIMER_MODE_NORMAL 0x00  // Default operation (no compare matching)
#define TIMER_PRESCALER_8 0x02  // clk/8
#define TIMER_PRESCALER_64 0x03  // clk/64
#define TIMER2_PRESCALER_64 0x04  // clk/64

// DDR/Pins/Outputs
#define PORT_B_DDR (1 << 0) | (1 << 1) | (1 << 2)  // Pins 8-10 in use as outputs
#define PORT_D_DDR (1 << 7)  // Pin 7 (output), Pin 6 (input)
#define PORT_B_WALL_OUT (1 << 2)  // Output when wall detected
#define PORT_B_LWHEEL_OUT (1 << 0)  // Left wheel only
#define PORT_B_RWHEEL_OUT (1 << 1)  // Left wheel only
#define PORT_B_BOTH_WHEELS_OUT PORT_B_LWHEEL_OUT | PORT_B_RWHEEL_OUT  // Both wheels
#define PORT_D_TRIGGER (1 << 7)  // Sensor trigger on pin 7
#define PORT_D_ECHO (1 << 6)  // Sensor echo on pin 6

// I/O ports
typedef struct io_port {
  uint8_t in;
  uint8_t ddr;
  uint8_t data;
} io_port_t;

// 8 bit timer
typedef struct timer8 {
  uint8_t controlA;
  uint8_t controlB;
  uint8_t counter;
  uint8_t outputCompareA;
  uint8_t outputCompareB;
} timer8_t;

//16 bit timer
typedef struct timer16 {
  uint8_t controlA;
  uint8_t controlB;
  uint16_t controlC;
  uint16_t counter;
  uint16_t inputCapture;
  uint16_t outputCompareA;
  uint16_t outputCompareB;
} timer16_t;

#endif  // AVR_OBJECTS_H
