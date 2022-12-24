#define PIN_INPUT_VOLTAGE_HALF 35

void setup()
{
   Serial.begin(115200);
}

void loop()
{
    int analogvalue = analogRead(PIN_INPUT_VOLTAGE_HALF);
    Serial.print("Voltage= ");                 // prints the voltage value in the serial monitor
    Serial.print(analogvalue);
    Serial.println(" Volts");
    delay(1000);
}