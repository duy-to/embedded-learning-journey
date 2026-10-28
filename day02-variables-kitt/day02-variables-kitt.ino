// Day 2 - Variables + for loops: "KITT" light that runs back and forth
// Wiring: pins 13, 12, 11 -> 220 ohm resistor -> LED -> GND

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  int speed = 200;
  for (int pin = 13; pin >= 11; pin--) {
    digitalWrite(pin, HIGH); delay(speed);
    digitalWrite(pin, LOW); delay(100);
  }
  for (int pin = 11; pin <= 13; pin++) {
    digitalWrite(pin, HIGH); delay(speed);
    digitalWrite(pin, LOW); delay(100);
  }
}
