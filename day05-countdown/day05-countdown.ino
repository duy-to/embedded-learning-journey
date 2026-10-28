// Day 5 (Q2) - for loop counting down: 10, 9, ... 1, then "Phong!" (launch)

int i;

void setup() {
  Serial.begin(115200);
}

void loop() {
  for (i = 10; i >= 1; i--) {
    Serial.println(i);
    delay(1000);
  }
  Serial.println("Phong!");
}
