// Sketch to use battery powered a LILYGO® TTGO ESP32-WROVER-E Board
// Coupled with a AM2302 temperature and humidity sensor
// to log readings hourly and report back daily via REST.
//
// Uses deep sleep mode to achieve one year of data logging between
// battery recharges
//
// Ref: based on   http://educ8s.tv/esp32-deep-sleep-tutorial 


#define uS_TO_S_FACTOR 1000000LL  /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP  3LL        /* Time ESP32 will go to sleep (in seconds) */

RTC_DATA_ATTR int bootCount = 0;

int GREEN_LED_PIN = 25;
int YELLOW_LED_PIN = 26;

void setup(){

  pinMode(GREEN_LED_PIN,OUTPUT);
  pinMode(YELLOW_LED_PIN,OUTPUT);
  delay(500);
  
  if(bootCount == 0) //Run this only the first time
  {
      digitalWrite(YELLOW_LED_PIN,HIGH);
      bootCount = bootCount+1;
  }else
  {
      digitalWrite(GREEN_LED_PIN,HIGH);
  }
  
  delay(3000);

  digitalWrite(GREEN_LED_PIN,LOW);
  digitalWrite(YELLOW_LED_PIN,LOW);

  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  esp_deep_sleep_start();
}

void loop(){
  
}
