const int ledPin = 18;
const unsigned long blinkInterval = 500;

unsigned long lastToggle = 0;
bool ledOn = false;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long now = millis();
  if (now - lastToggle >= blinkInterval) {
    lastToggle = now;
    ledOn = !ledOn;
    digitalWrite(ledPin, ledOn);
  }
}
