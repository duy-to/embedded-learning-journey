int count = 0;

const int ledPins[] = { 16, 17, 18, 19 };
const int arrayCount = sizeof(ledPins) / sizeof(ledPins[0]);

unsigned long now = 0;
unsigned long lastCheck = 0;
const unsigned long interval = 1000;

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < arrayCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void binaryCount() {
  for (int i = 0; i < arrayCount; i++) {
    digitalWrite(ledPins[i], count & (1 << i));  //bitRead(count, i);
  }
  Serial.println(count, BIN);
  count++;
  if (count > 15) {
    count = 0;
  }
}

void loop() {
  now = millis();
  if (now - lastCheck >= interval) {
    binaryCount();
    lastCheck = now;
  }
}
