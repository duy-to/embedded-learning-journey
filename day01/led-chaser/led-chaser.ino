// Day 1 (extra) - 3 LED chaser
// Wiring: pins 13, 12, 11 -> 220 ohm resistor -> LED -> shared GND row -> Arduino GND
// Version 2: same effect using a for loop counting down

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  for (int pin = 13; pin >= 11; pin--) {
    digitalWrite(pin, HIGH);
    delay(200);
    digitalWrite(pin, LOW);
  }
}
