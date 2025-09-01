#include <Arduino.h>
#include "SevenSegmentLed.h"
#include "SevenSegmentLedDriver.h"
#ifdef DEBUG
#include "avr8-stub.h"
#endif // DEBUG

// put function declarations here:
// Statically allocate the SevenSegmentLed object instead of using 'new'.
// This avoids dynamic memory allocation, which can be problematic on
// micro-controllers due to heap fragmentation.
SevenSegmentLed digital_led(2, 3, 4, 5, 6, 7, 8, 9);
seven_segment_led_driver controller(digital_led, 1000);
void setup()
{
#ifdef DEBUG
  debug_init();
  Serial.begin(9600);
#endif // DEBUG
}

void loop()
{
  controller.digital_cycle();
}
