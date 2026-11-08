// Day 4 - Check if an LED current is safe using if / else if / else
// I = (Vsource - Vled) / R. Above 20 mA is dangerous, below 5 mA the LED is dim.
// Try R = 220, 100, 47 and see which branch runs.

void setup() {
  Serial.begin(115200);
  float source = 5;
  float vLED = 2;
  int R = 220;
  float iR = (source - vLED) / R;

  if (iR > 0.02) { Serial.print("Nguy hiem dong qua lon: "); Serial.print(iR * 1000); Serial.println(" mA"); }
  else if (iR < 0.005) { Serial.print("Dong qua yeu den se mo: "); Serial.print(iR * 1000); Serial.println(" mA"); }
  else { Serial.println("Ngon luon em oi!!"); }
}

void loop() {
}
