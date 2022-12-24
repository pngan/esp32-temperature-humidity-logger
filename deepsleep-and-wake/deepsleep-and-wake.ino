// Sketch to use battery powered a LILYGO® TTGO ESP32-WROVER-E Board
// Coupled with a AM2302 temperature and humidity sensor
// to log readings hourly and report back daily via REST.
//
// Uses deep sleep mode to achieve one year of data logging between
// battery recharges
//
// Ref: based on   http://educ8s.tv/esp32-deep-sleep-tutorial

//#include "epd_driver.h"

#define uS_TO_S_FACTOR 1000000LL /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP 5LL        /* Time ESP32 will wake in (in seconds) */

RTC_DATA_ATTR int bootCount = 0;


void setup() {
  bootCount = bootCount + 1;
  delay(1000);

  if ((bootCount % 2) == 0)
  {
    delay(2000);
  }

  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  esp_deep_sleep_start();
}

void loop() {
}
