const int potPin = 34;
const int ledCount = 3;
const int bluePin = 19;
const int ledPins[ledCount] = { 18, 17, 16 };
const int thresholds[ledCount] = { 25, 50, 75 };
const unsigned long readInterval = 100;
unsigned long lastRead = 0;
unsigned long lastBlueToggle = 0;
float lastPrintedPercent = 0;
float percent = 0;
bool blueLedOn = true;
float readPercent(int pin) {
  int totalValue = 0;
  for (int i = 1; i <= 10; i++) {
    int rawValue = analogRead(pin);
    totalValue += rawValue;
  }
  float average = totalValue / 10.0;
  return average * 100.0 / 4095;
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
  pinMode(bluePin, OUTPUT);
}

void loop() {
  unsigned long now = millis();
  if (now - lastRead >= readInterval) {
    lastRead = now;
    percent = readPercent(potPin);
    if (abs(percent - lastPrintedPercent) >= 2) {
      Serial.println(percent);
      lastPrintedPercent = percent;
    }
    updateLeds(percent);
  }

  float blinkInterval = 1000 - percent * 9.5;
  if (now - lastBlueToggle >= blinkInterval) {
    lastBlueToggle = now;
    digitalWrite(bluePin, blueLedOn);
    blueLedOn = !blueLedOn;
  }
}
