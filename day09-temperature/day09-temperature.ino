float temperature[7];

void setup() {
  Serial.begin(115200);
}

void wait() {
  while (!Serial.available()) {}
}

void clear() {
  while (Serial.available() > 0) { Serial.read(); }
}

float measureTemp() {
  float total = 0;
  for (int i = 0; i <= 6; i++) {
    Serial.println();
    Serial.print("Please Enter Temperature of Day: ");
    Serial.println(i + 1);
    wait();
    float t = Serial.parseFloat();
    clear();
    total += t;
    temperature[i] = t;
  }
  return total;
}

void averageTemp(float total) {
  float averageTemperature = total / 7;
  Serial.print("Average Temperature of the week is: ");
  Serial.println(averageTemperature);
}

void highestTemp() {
  bool printedOne = false;
  float measure = temperature[0];
  for (int i = 0; i <= 6; i++) {
    if (temperature[i] > measure) {
      measure = temperature[i];
    }
  }
  Serial.print("Day ");
  for (int i = 0; i <= 6; i++) {
    if (temperature[i] == measure) {
      if (printedOne) {
        Serial.print(", ");
      }
      Serial.print(i + 1);
      printedOne = true;
    }
  }
  Serial.print(" has the highest temperature: ");
  Serial.println(measure);
}

void lowestTemp() {
  bool printedOne = false;
  float measure = temperature[0];
  for (int i = 0; i <= 6; i++) {
    if (temperature[i] < measure) {
      measure = temperature[i];
    }
  }
  Serial.print("Day ");
  for (int i = 0; i <= 6; i++) {
    if (temperature[i] == measure) {
      if (printedOne) { Serial.print(", "); }
      Serial.print(i + 1);
      printedOne = true;
    }
  }
  Serial.print(" has the lowest temperature: ");
  Serial.println(measure);
}

void loop() {
  averageTemp(measureTemp());
  highestTemp();
  lowestTemp();
}
