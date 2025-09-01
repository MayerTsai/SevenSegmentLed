#include "SevenSegmentLed.h"

// The segment map is now stored in PROGMEM (Flash) to save SRAM.
// It is also const as it should not be modified.
// It only contains data for the 7 segments (A-G). The dot is handled by setDot().
const uint8_t SevenSegmentLed::segmentMap[10][7] PROGMEM = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
};

SevenSegmentLed::SevenSegmentLed(int pina = 2, int pinb = 3, int pinc = 4, int pind = 5,
                                 int pine = 6, int pinf = 7, int ping = 8, int pinx = 9)
{
  leds[0] = pina;
  leds[1] = pinb;
  leds[2] = pinc;
  leds[3] = pind;
  leds[4] = pine;
  leds[5] = pinf;
  leds[6] = ping;
  leds[7] = pinx;
  for (int i = 0; i < 8; i++)
    pinMode(leds[i], OUTPUT);
  clearDisplay();
}

void SevenSegmentLed::clearDisplay()
{
  for (int i = 0; i < 8; i++)
    digitalWrite(leds[i], LOW); // Turn off all segments and the dot
}

void SevenSegmentLed::displayNumber(int number)
{
  if (number < 0 || number > 9)
    return;

  for (int i = 0; i < 7; i++)
  {
    // Read segment state from PROGMEM and write to the pin
    uint8_t state = pgm_read_byte_near(&segmentMap[number][i]);
    digitalWrite(leds[i], state);
  }
}
void SevenSegmentLed::setDot(bool on)
{
  // The 8th LED (index 7) is the dot.
  digitalWrite(leds[7], on ? HIGH : LOW);
}