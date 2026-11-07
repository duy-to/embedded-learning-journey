int count = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Booting...");
}

void loop() {
  count += 1;
  Serial.print("Loop count: ");
  Serial.println(count);
  delay(1000);
}
