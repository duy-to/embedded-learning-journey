const int ledPin = 2;
bool shouldBlink = true;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void blink5Times(int blinkDelay) {
  for (int i = 1; i <= 5; i++) {
    digitalWrite(ledPin, HIGH);
    delay(blinkDelay);
    digitalWrite(ledPin, LOW);
    delay(blinkDelay);
    Serial.print("Blink: ");
    Serial.println(i);
  }
  Serial.println("Done!");
}

void loop() {
  if (shouldBlink) {
    blink5Times(200);
    shouldBlink = false;
  }
}
