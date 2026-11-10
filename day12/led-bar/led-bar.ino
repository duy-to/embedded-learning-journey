const int potPin = 34;
const int ledCount = 3;
const int ledPins[ledCount] = { 18, 17, 16 };
const int thresholds[ledCount] = { 25, 50, 75 };
const unsigned long readInterval = 100;

unsigned long lastRead = 0;

float readPercent(int pin) {
  int rawValue = analogRead(pin);
  return rawValue * 100.0 / 4095;
}

void updateLeds(float percent) {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], percent >= thresholds[i]);
  }
}

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  unsigned long now = millis();
  if (now - lastRead >= readInterval) {
    lastRead = now;
    float percent = readPercent(potPin);
    Serial.println(percent);
    updateLeds(percent);
  }
}
