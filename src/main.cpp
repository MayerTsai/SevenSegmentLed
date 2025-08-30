#include <Arduino.h>
#include "SevenSegmentLed.h"
#ifdef DEBUG
#include "avr8-stub.h"
#endif // DEBUG

// put function declarations here:
// Statically allocate the SevenSegmentLed object instead of using 'new'.
// This avoids dynamic memory allocation, which can be problematic on
// micro-controllers due to heap fragmentation.
SevenSegmentLed digital_leds(2, 3, 4, 5, 6, 7, 8, 9);
int number = 0;

void setup()
{
#ifdef DEBUG
  debug_init();
  Serial.begin(9600);
#endif // DEBUG
}

void loop()
{
  // put your main code here, to run repeatedly:
  digital_leds.displayNumber(number);
  number++;
  if (number > 9)
    number = 0;
  delay(1000);
}
