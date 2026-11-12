const int potPin = 34;
const int ledPinsLevel[] = { 0, 1024, 2048, 3072 };

const int ledPins[] = { 16, 17, 18, 19 };
const int arrayCount = sizeof(ledPins) / sizeof(ledPins[0]);

unsigned long now = 0;
unsigned long lastCheck = 0;
const unsigned long interval = 100;

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < arrayCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void brightnessLevels() {
  int analog = analogRead(potPin);
  for (int i = 0; i < arrayCount; i++) {
    int brightness = analog - ledPinsLevel[i];
    brightness = constrain(brightness, 0, 1023);
    analogWrite(ledPins[i], (brightness >> 2));
  }
}

void loop() {
  now = millis();
  if (now - lastCheck >= interval) {
    brightnessLevels();
    lastCheck = now;
  }
}
