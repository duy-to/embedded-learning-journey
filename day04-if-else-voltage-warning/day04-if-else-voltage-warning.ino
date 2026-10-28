// Day 4 - if / else if / else
// 1) setup(): classify a temperature into ranges with && (no gaps, no overlaps)
// 2) loop(): read a potentiometer, print the voltage, and blink a red LED as a
//    "High Voltage" warning when it goes above 4 V; green LED on when safe.
// Wiring: potentiometer outer legs -> 5V and GND, middle leg -> A5
//         red LED on pin 10, green LED on pin 13 (each with 220 ohm to GND)
// Lesson learned: a floating analog pin gives random drifting readings.

int WarningVoltage = 4;
int PIN_READ = A5;
int redLED = 10;
int greenLED = 13;
float inputVal;
int dt = 500;
int dtL = 50;
int start = 1;
int times = 20;
int initialValue = 1;
float temp = 30;

void setup() {
  Serial.begin(115200);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  if (temp >= 30 && temp < 40) { Serial.print("Hom nay troi nong: "); Serial.println(temp, 1); }
  else if (temp >= 40 && temp <= 45) { Serial.print("Hom nay troi rat nong: "); Serial.println(temp, 1); }
  else if (temp <= 20 && temp >= 12) { Serial.print("Hom nay troi mat: "); Serial.println(temp, 1); }
  else if (temp < 12 && temp > 5) { Serial.print("Hom nay troi lanh: "); Serial.println(temp, 1); }
  else if (temp > 20 && temp < 30) { Serial.print("Hom nay troi de chiu: "); Serial.println(temp, 1); }
  else { Serial.print("Hom nay khong nen ra ngoai - "); Serial.println(temp, 1); }
}

void loop() {
  inputVal = (5.00 / 1023) * analogRead(PIN_READ);
  Serial.print("The input voltage is: ");
  Serial.print(inputVal, 2);
  Serial.println("V");
  delay(dt);
  if (inputVal >= WarningVoltage) {
    digitalWrite(greenLED, LOW);
    Serial.println("Caution: High Voltage");
    for (start = initialValue; start <= times; start++) {  // reset the counter every time
      digitalWrite(redLED, HIGH);
      delay(dtL);
      digitalWrite(redLED, LOW);
      delay(dtL);
    }
  } else {
    digitalWrite(greenLED, HIGH);
  }
}
