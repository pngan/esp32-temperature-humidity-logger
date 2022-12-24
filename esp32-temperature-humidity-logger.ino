// Sketch to use battery powered a LILYGO® TTGO ESP32-WROVER-E Board
// Coupled with a AM2302 temperature and humidity sensor
// to log readings hourly and report back daily via REST.
//
// Uses deep sleep mode to achieve one year of data logging between
// battery recharges
//
// Ref: based on   http://educ8s.tv/esp32-deep-sleep-tutorial 
#include <stdio.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "localwifi.h" // Do not check this file into git

#define uS_TO_S_FACTOR 1000000LL  /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP  5LL        /* Time ESP32 will go to sleep (in seconds) */
#define PIN_INPUT_VOLTAGE_HALF 35

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

  int batteryVoltage = analogRead(PIN_INPUT_VOLTAGE_HALF) * 2;
  char json[256];
  sprintf(json, "{\n\"loc\":\"home\",\n\"bat\":%d", batteryVoltage);
  int httpResponseCode = http.POST(json);
  
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
