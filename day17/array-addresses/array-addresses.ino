int ledPins[3] = { 0, 50, 100 };
int countNumbers = sizeof(ledPins) / sizeof(ledPins[0]);
void setup() {
  Serial.begin(115200);
  for (int i = 0; i <= countNumbers; i++) {
    Serial.println((uint32_t)&ledPins[i],HEX);
  }
  Serial.println(ledPins[3]);
}

void loop() {
  // put your main code here, to run repeatedly:
}
