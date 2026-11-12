const byte MSB = 0b1000;
const byte LSB = 0b0001;
byte ledMask = 0b0001;
bool movingLeft = true;

const int ledPins[] = { 16, 17, 18, 19 };
const int numberOfLeds = sizeof(ledPins) / sizeof(ledPins[0]);

unsigned long lastCheck = 0;
const unsigned long interval = 200;

byte moveLed() {
  if (movingLeft) {
    ledMask <<= 1;
    if (ledMask == MSB) { movingLeft = !movingLeft; }
    return ledMask;
  }
  if (!movingLeft) {
    ledMask >>= 1;
    if (ledMask == LSB) { movingLeft = true; }
    return ledMask;
  }
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
  Serial.begin(115200);
}

void loop() {
  unsigned long now = millis();
  if (now - lastCheck >= interval) {
    lightUpLed(moveLed());
    lastCheck = now;
    Serial.println(ledMask, BIN);
  }
}
