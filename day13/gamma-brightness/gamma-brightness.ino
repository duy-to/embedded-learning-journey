const int potPin = 34;
const int ledPin = 18;
const int ledPins[] = { 16, 17, 18 };
const int ledPinsLevel[] = { 0, 33, 66 };
unsigned long now = 0;
unsigned long lastLevelChange = 0;
const unsigned long readInterval = 100;

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < 3; i++) { pinMode(ledPins[i], OUTPUT); }
}

float readPercent(int pin) {
  int totalValue = 0;
  for (int i = 1; i <= 10; i++) {
    int rawValue = analogRead(pin);
    totalValue += rawValue;
  }
  float average = totalValue / 10.0;
  return average * 100.0 / 4095;
}

void dimOneLed(float percent) {
  float rate = percent / 100;
  float brightnessLevel = rate * rate * 255;
  brightnessLevel = constrain(brightnessLevel, 0, 255);
  analogWrite(ledPin, brightnessLevel);
  Serial.println(brightnessLevel);
}

void updateLedBar(float percent) {
  for (int i = 0; i < 3; i++) {
    float sectionPercent = percent - ledPinsLevel[i];
    float rate = sectionPercent / 33.0;
    rate = constrain(rate, 0, 1);
    float brightnessLevel = rate * rate * 255;
    brightnessLevel = constrain(brightnessLevel, 0, 255);
    analogWrite(ledPins[i], brightnessLevel);
  }
}

void loop() {
  now = millis();
  if (now - lastLevelChange >= readInterval) {
    lastLevelChange = now;
    float percent = readPercent(potPin);
    updateLedBar(percent);
  }
}
