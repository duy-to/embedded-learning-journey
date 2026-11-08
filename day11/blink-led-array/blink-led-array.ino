const int ledCount = 2;
const int ledPins[ledCount] = { 18, 13 };
const unsigned long intervals[ledCount] = { 500, 250 };

unsigned long lastToggles[ledCount] = { 0, 0 };
bool ledOn[ledCount] = { false, false };

void setup() {
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  unsigned long now = millis();
  for (int i = 0; i < ledCount; i++) {
    if (now - lastToggles[i] >= intervals[i]) {
      lastToggles[i] = now;
      ledOn[i] = !ledOn[i];
      digitalWrite(ledPins[i], ledOn[i]);
    }
  }
}
