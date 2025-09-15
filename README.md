# parent detector
Just a simple ultrasonic sensor device that outputs to terminal using bluetooth

Hardware setup:

Modules required:
1. Arduino UNO
2. HC-SR04 Ultrasonic Sensor
3. HC-05 Bluetooth Module
4. any buzzer

Wiring:
HC-SR04:
  VCC->5V
  trig->D9
  echo->D10
  GND->GND
HC-05:
  VCC->5V
  GND->GND
  TXD->D8
  RXD->D7
Buzzer:
  +ve->D6
  -ve->GND

VCC:power delivery | GND:ground | D[x]:digital pin [x]

Software setup:

Bluetooth:
  1. Connect to "HC-05" using bluetooth and either "1234" or "0000" as password
  2. Open terminal (MacOS) and enter screen "/dev/ttyACM0 9600"
  3. To exit, Control + A, K
