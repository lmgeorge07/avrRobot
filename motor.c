#include "motor.h"

/* PWM - dual ccw rotation */
void run() {
  portb->data = PORT_B_BOTH_WHEELS_OUT;
  delay_in_10us(MOTOR_CCW_2);
  portb->data = 0x00;
  delay_in_ms(MOTOR_PERIOD_MS);
}

/* PWM dual stop */
void stop() {
  portb->data = PORT_B_BOTH_WHEELS_OUT;
  delay_in_10us(MOTOR_STOP);
  portb->data = 0x00;
  delay_in_ms(MOTOR_PERIOD_MS);
}

/* PWM - right wheel stop, left wheel cw rotation */
void reverse_left() {
  portb->data = PORT_B_LWHEEL_OUT;
  delay_in_10us(MOTOR_CW_2);
  portb->data = 0x00;
  delay_in_ms(MOTOR_PERIOD_MS);
}

/* PWM - left wheel stop, right wheel cw rotation */
void reverse_right() {
  portb->data = PORT_B_RWHEEL_OUT;
  delay_in_10us(MOTOR_CW_2);
  portb->data = 0x00;
  delay_in_ms(MOTOR_PERIOD_MS);
}
