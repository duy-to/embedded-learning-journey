// Day 5 (Q1) - for loop: count from 1 to 10 on the Serial Monitor (115200 baud)

int i;

void setup() {
  Serial.begin(115200);
}

void loop() {
  for (i = 1; i <= 10; i++) {
    Serial.println(i);
    delay(1000);
  }
}
