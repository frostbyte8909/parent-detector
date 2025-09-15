#include <SoftwareSerial.h>

const uint8_t TRIG_PIN = 9;
const uint8_t ECHO_PIN = 10;
const uint8_t BUZZER_PIN = 6;
const uint8_t BT_RX = 8;
const uint8_t BT_TX = 7;
const int TRIP_CM = 85;

SoftwareSerial BT(BT_RX, BT_TX);

long measureDistanceCm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 38000UL);
  if (duration == 0) return -1;
  return (duration * 343L) / 20000L;
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
  BT.begin(9600);
}

void loop() {
  long cm = measureDistanceCm();
  bool tripped = (cm > 0 && cm < TRIP_CM);
  digitalWrite(BUZZER_PIN, tripped ? HIGH : LOW);
  if (tripped) {
    BT.println("intruder detected");
    delay(300);
  }
  delay(50);
}
