#include "SevenSegmentLedDriver.h"

seven_segment_led_driver::seven_segment_led_driver(SevenSegmentLed &led, unsigned long duration)
    : _blinking_duration(duration),
      _last_blink_time(0),
      _is_on(true),
      _last_number(0)
{
  _led = &led;
}

void seven_segment_led_driver::set_blinking_duration(unsigned long duration)
{
  _blinking_duration = duration;
}

unsigned long seven_segment_led_driver::get_blinking_duration()
{
  return _blinking_duration;
}

void seven_segment_led_driver::blink(int number)
{
  unsigned long now = millis();
  if (now - _last_blink_time >= _blinking_duration)
  {
    _is_on = !_is_on;
    if (_is_on)
      _led->displayNumber(number);
    else
      _led->clearDisplay();
    _last_blink_time = now;
  }
}

void seven_segment_led_driver::digital_cycle()
{
  unsigned long now = millis();                     // get the current time
  if (now - _last_blink_time >= _blinking_duration) // if duration of now and the last recorded time is larger than the set_time
  {
    // do something here
    _last_number++;
    if (_last_number > 9)
      _last_number %= 10;
    _led->displayNumber(_last_number);

    _last_blink_time = now; // reset the the recorded time to now
  }
}