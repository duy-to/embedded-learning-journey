// Day 2 - Global variable + if: LEDs run back and forth, faster each round.
// When speed gets too fast, all 3 LEDs flash twice to "celebrate", then reset to slow.
// Wiring: pins 13, 12, 11 -> 220 ohm resistor -> LED -> GND

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

int speed = 200;  // global: keeps its value between loop() runs

void loop() {
  for (int pin = 13; pin >= 11; pin--) {
    digitalWrite(pin, HIGH);
    delay(speed);
    digitalWrite(pin, LOW);
    delay(100);
  }
  for (int pin = 11; pin <= 13; pin++) {
    digitalWrite(pin, HIGH);
    delay(speed);
    digitalWrite(pin, LOW);
    delay(100);
  }
  speed = speed - 20;
  if (speed <= 40) {
    for (int number = 1; number <= 2; number++) {
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(13, HIGH);
      delay(100);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      delay(100);
    }
    speed = 200;
    delay(1000);
  }
}
