#ifndef SEVEN_SEGMENT_LED_H
#define SEVEN_SEGMENT_LED_H

#include <Arduino.h>
#include <avr/pgmspace.h>

class SevenSegmentLed
{
private:
  int leds[8];
  // This map is now in Flash memory (PROGMEM) to save SRAM.
  static const uint8_t segmentMap[10][7] PROGMEM;

public:
  SevenSegmentLed(int, int, int, int, int, int, int, int);
  ~SevenSegmentLed() = default;
  SevenSegmentLed(const SevenSegmentLed &) = delete;            // Disable copy constructor
  SevenSegmentLed &operator=(const SevenSegmentLed &) = delete; // Disable assignment operator

  void displayNumber(int number);
  void clearDisplay();
  void setDot(bool on);
};

#endif // SEVEN_SEGMENT_LED_H
