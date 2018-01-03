/*
 * This software read GPIO input
 * to trigger joystick btn press accordingly
 */

#include <Arduino.h>
#include "Bounce2.h"

// PIN_D7 corresponds to physical pin 12
#define BTN_PIN PIN_D7
// PIN_F0 corresponds to physical pin 21
// https://www.pjrc.com/teensy/td_digital.html
// https://www.pjrc.com/teensy/card2b.pdf
#define X_AXIS_PIN PIN_F0
#define JOY_NUM 1

Bounce debouncer = Bounce();

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BTN_PIN, INPUT_PULLUP);
  debouncer.attach(BTN_PIN);
  debouncer.interval(1); // interval in ms
}

void loop()
{
  // try to update btn state only if GPIO state has changed
  if(debouncer.update())
  {
    // we are in pull-up configuration so high state mean btn is released
    if (debouncer.read())
    {
      digitalWrite(LED_BUILTIN, LOW);
      Joystick.button(JOY_NUM, 0);
    } else {
      digitalWrite(LED_BUILTIN, HIGH);
      Joystick.button(JOY_NUM, 1);
    }
  }
  // update joystick X axis with analog value for potentiometer
  Joystick.X(analogRead(X_AXIS_PIN));
}
