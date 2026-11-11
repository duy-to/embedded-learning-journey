const int potPin = 34;
const int ledPins[] = { 16, 17, 18 };
const int ledPinsLevel[] = { 0, 33, 66 };
const int minBrightness = 0;
const int maxBrightness = 255;
unsigned long now = 0;
unsigned long lastLevelChange = 0;
const unsigned long stepInterval = 50;
const unsigned long readInterval = 100;
const int brightnessStep = 5;
int brightness = 0;
bool goingUp = true;
float brightnessLevel = 0;
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

void ledDim() {
  analogWrite(ledPins[0, 1, 2], brightness);
  Serial.println(brightness);
  if (goingUp) {
    brightness += brightnessStep;
    if (brightness > maxBrightness) {
      goingUp = !goingUp;
      brightness = maxBrightness - brightnessStep;
    }
  } else {
    brightness -= brightnessStep;
    if (brightness < minBrightness) {
      goingUp = !goingUp;
      brightness = minBrightness + brightnessStep;
    }
  }
}

void loop() {
  now = millis();
  if (now - lastLevelChange >= readInterval) {
    lastLevelChange = now;
    float percent = readPercent(potPin);
    for (int i = 0; i < 3; i++) {
      float sectionPercent = percent - ledPinsLevel[i];
      brightnessLevel = sectionPercent * 7.727;
      brightnessLevel = constrain(brightnessLevel, 0, 255);
      analogWrite(ledPins[i], brightnessLevel);
    }
    Serial.println(brightnessLevel);
  }
}
