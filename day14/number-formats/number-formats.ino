const int numbers[] = { 13, 60, 100, 200 };
const int numberCount = sizeof(numbers) / sizeof(numbers[0]);
String line = "----------------------------";

void setup() {
  Serial.begin(115200);
}

void clearSerialInput() {
  while (Serial.available() > 0) { Serial.read(); }
}

void wait() {
  while (!Serial.available()) {}
}

void loop() {
  for (int i = 0; i < numberCount; i++) {
    Serial.println(numbers[i]);
    Serial.println(numbers[i], BIN);
    Serial.println(numbers[i], HEX);
    Serial.println(line);
  }
  wait();
  clearSerialInput();
}
