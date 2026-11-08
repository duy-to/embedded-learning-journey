// Day 5 (Q5) - Try resistors 100..1000 ohm (step 100) for an LED on 5 V (Vf = 2 V)
// Current in mA = (V - Vf) * 1000 / R. Print "OK!" when it is between 5 and 20 mA.
// Lesson learned: (float) cast, otherwise (5 - 2) * 1000 / R is integer division.

int i;
int v = 5;
int vf = 2;
float j = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  for (i = 100; i <= 1000; i += 100) {
    Serial.println(i);
    j = ((float)v - vf) * 1000 / i;
    Serial.println(j);
    if (j >= 5 && j <= 20) {
      Serial.println("OK!");
    }
    delay(1000);
  }
}
