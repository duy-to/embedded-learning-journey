const int buttonPin = 4;
const int ledCount = 2;
const int ledPins[ledCount] = { 18, 13 };
const unsigned long intervals[ledCount] = { 500, 250 };
const unsigned long buttonInterval = 50;

unsigned long lastToggles[ledCount] = { 0, 0 };
bool ledOn[ledCount] = { false, false };
unsigned long lastButtonRead = 0;
int lastButtonState = HIGH;
bool isBlinking = true;

bool isButtonPressed(unsigned long now) {
  bool pressed = false;
  if (now - lastButtonRead >= buttonInterval) {
    lastButtonRead = now;
    int buttonState = digitalRead(buttonPin);
    if (buttonState == LOW && lastButtonState == HIGH) {
      pressed = true;
    }
    lastButtonState = buttonState;
  }
  return pressed;
}

void updateLeds(unsigned long now) {
  for (int i = 0; i < ledCount; i++) {
    if (now - lastToggles[i] >= intervals[i]) {
      lastToggles[i] = now;
      ledOn[i] = !ledOn[i];
      digitalWrite(ledPins[i], ledOn[i]);
    }
  }
}

void turnLedsOff() {
  for (int i = 0; i < ledCount; i++) {
    ledOn[i] = false;
    digitalWrite(ledPins[i], LOW);
  }
}

void setup() {
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  unsigned long now = millis();
  if (isButtonPressed(now)) {
    isBlinking = !isBlinking;
  }
  if (isBlinking) {
    updateLeds(now);
  } else {
    turnLedsOff();
  }
}
