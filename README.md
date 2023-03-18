# LILYGO TTGO T-Energy Notes

- Official GitHub reference: https://github.com/LilyGO/LILYGO-T-Energy
- BUILTIN LED is PIN 5, digital output mode (See top right diagram on page 2 of pdf)
- Battery voltage is PIN 35, analog input. Note the value is half the actual voltage because of a 1:1 voltage divider. (See bottom right diagram on page 2 of pdf)
- It is important to monitor the battery voltage of the builtin lithium battery because these batteries are not protected by a battery management system, and so can be damaged if drained below
- Since the ESP32 requires 3.3V to operate, it might be good to recharge the battery when the battery reduces to this voltage, because the unit will probably stop functioning reliably if the voltage drops further.

