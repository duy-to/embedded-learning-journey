int lastState = 1;
const int buttonPin = 4;
int nextLed = 0;
byte ledMask = 0b0000;
int ledPins[] = { 16, 17, 18, 19 };
int numberOfLeds = sizeof(ledPins) / sizeof(ledPins[0]);
unsigned long now = 0;
unsigned long lastCheck = 0;
unsigned long interval = 100;
const unsigned long debounceInterval = 50;
unsigned long lastChangeTime = 0;
int lastReading = HIGH;
bool buttonPressed() {
  bool pressed = false;
  now = millis();
  int currentState = digitalRead(buttonPin);
  if (currentState != lastReading) {
    lastChangeTime = now;
    lastReading = currentState;
  }
  if (now - lastChangeTime >= debounceInterval) {
    if (currentState == 0 && lastState == 1) {
      pressed = true;
    }
    lastState = currentState;
  }
  return pressed;
}

byte toggleNextLed() {
  ledMask ^= (1 << nextLed);
  nextLed++;
  if (nextLed >= numberOfLeds) { nextLed = 0; }
  return ledMask;
}

void lightUpLed(byte Mask) {
  for (int i = 0; i < numberOfLeds; i++) {
    digitalWrite(ledPins[i], bitRead(Mask, i));
  }
}

void setup() {
  for (int i = 0; i < numberOfLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  now = millis();
  if (buttonPressed()) {
    if (now - lastCheck >= interval) {
      lightUpLed(toggleNextLed());
      lastCheck = now;
      Serial.println(ledMask, BIN);
    }
  }
}
