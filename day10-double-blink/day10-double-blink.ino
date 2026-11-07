const int ledPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void doubleBlink(int blinkDelay, int pauseDelay) {
  for (int i = 1; i <= 2; i++) {
    digitalWrite(ledPin, HIGH);
    delay(blinkDelay);
    digitalWrite(ledPin, LOW);
    delay(blinkDelay);
  }
  delay(pauseDelay);
}

void loop() {
  doubleBlink(200, 1000);
}
