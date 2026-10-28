// Day 1 - Blink an LED on pin 13
// Wiring: pin 13 -> 220 ohm resistor -> LED long leg (+), LED short leg (-) -> GND
// Lesson learned: never put both LED legs in the same breadboard row (short circuit)

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  delay(200);
  digitalWrite(13, HIGH);
  delay(500);
}
