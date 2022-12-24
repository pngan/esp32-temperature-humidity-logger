// Sketch to use battery powered a LILYGO® TTGO ESP32-WROVER-E Board
// Coupled with a AM2302 temperature and humidity sensor
// to log readings hourly and report back daily via REST.
//
// Uses deep sleep mode to achieve one year of data logging between
// battery recharges
//
// Ref: based on   http://educ8s.tv/esp32-deep-sleep-tutorial 

#include <WiFi.h>
#include <HTTPClient.h>
#include "localwifi.h" // Do not check this file into git

const String url = "https://eo4avu3kqpzqnl3.m.pipedream.net";

#define uS_TO_S_FACTOR 1000000LL  /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP  5LL        /* Time ESP32 will go to sleep (in seconds) */


void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.print("OK! IP=");
  Serial.println(WiFi.localIP());

  Serial.print("Posting " + url + "... ");
  HTTPClient http;
  http.begin(url);


  http.addHeader("Content-Type", "application/json");
  int httpResponseCode = http.POST("{\n\"sensor\":\"gps\",\n\"time\":1351824120,\n\"data\":[\n48.756080,\n2.302038\n]\n}");
  
  if (httpResponseCode > 0) {
    Serial.print("HTTP ");
    Serial.println(httpResponseCode);
    String payload = http.getString();
    Serial.println();
    Serial.println(payload);
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
    Serial.println(":-(");
  }

  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  esp_deep_sleep_start();
}

void loop(){
  
}
