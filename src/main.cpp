/*
 * This software read GPIO input
 * to trigger joystick btn press accordingly
 */

#include <Arduino.h>

// PIN_D7 corresponds to physical pin 12
#define BTN_PIN PIN_D7
// PIN_F0 corresponds to physical pin 21
// https://www.pjrc.com/teensy/td_digital.html
// https://www.pjrc.com/teensy/card2b.pdf
#define X_AXIS_PIN PIN_F0
#define JOY_NUM 1

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BTN_PIN, INPUT_PULLUP);
}

void loop()
{
  if(digitalRead(BTN_PIN)) {
    // turn the LED off by making the voltage LOW
    digitalWrite(LED_BUILTIN, LOW);
    Joystick.button(JOY_NUM, 0);
  } else {
    // turn the LED on (HIGH is the voltage level)
    digitalWrite(LED_BUILTIN, HIGH);
    Joystick.button(JOY_NUM, 1);
  }
  Joystick.X(analogRead(X_AXIS_PIN));
}
