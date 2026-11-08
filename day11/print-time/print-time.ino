unsigned long lastPrint = 0;
const unsigned long printInterval = 1000;

void setup() {
  Serial.begin(115200);
}

void loop() {
  unsigned long now = millis();
  if (now - lastPrint >= printInterval) {
    lastPrint = now;
    Serial.println(now);
  }
}
