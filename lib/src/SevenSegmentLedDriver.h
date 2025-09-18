#ifndef SEVEN_SEGMENT_LED_DRIVER_H
#define SEVEN_SEGMENT_LED_DRIVER_H

#include "SevenSegmentLed.h"

class seven_segment_led_driver
{
private:
  SevenSegmentLed *_led;
  unsigned long _blinking_duration;

  unsigned long _last_blink_time;
  bool _is_on;
  int _last_number;

public:
  seven_segment_led_driver(SevenSegmentLed &led, unsigned long duration = 1000);
  seven_segment_led_driver(const seven_segment_led_driver &) = delete;
  seven_segment_led_driver &operator=(const seven_segment_led_driver &) = delete;
  ~seven_segment_led_driver() = default;

  void set_blinking_duration(unsigned long duration);
  unsigned long get_blinking_duration();
  void blink(int number);
  void digital_cycle();
};

#endif // SEVEN_SEGMENT_LED_DRIVER_H