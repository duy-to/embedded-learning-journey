// Day 3 - Operators, Ohm's law and power, printed once on the Serial Monitor (115200 baud)
// Topics: float vs int division, casting with (float), % (remainder), mW units
// Expected output: 13.64 mA through the LED, 40.91 mW in the resistor, 1 Gio 2 Phut 5 Giay

void setup() {
  Serial.begin(115200);

  // V = I * R and P = V * I
  float I = 0.02;
  int R = 220;
  float V = I * R;
  Serial.print("Dien ap: ");
  Serial.print(V, 3);
  Serial.println(" V");

  float P = V * I * 1000;
  Serial.print("Cong suat: ");
  Serial.print(P, 3);
  Serial.println(" mW");

  // LED + 220 ohm resistor on a 5 V source (LED forward voltage ~2 V)
  int source = 5;
  int vLED = 2;
  int resistor = 220;
  int vResistor = source - vLED;
  Serial.print(vResistor);
  Serial.println(" V");
  float current = (float)vResistor / resistor * 1000;  // (float) avoids integer division (3 / 220 = 0)
  Serial.print("Cuong do dong dien di qua LED la: ");
  Serial.print(current, 2);
  Serial.println(" mA");
  float pR = vResistor * current;  // V * mA = mW
  Serial.print("Cong suat dien tro phai chiu la: ");
  Serial.print(pR, 2);
  Serial.println(" mW");

  // Convert seconds to hours, minutes, seconds with / and %
  int tong_giay = 3725;
  int gio = tong_giay / 3600;
  int con_lai = tong_giay % 3600;
  int phut = con_lai / 60;
  int giay = con_lai % 60;
  Serial.print(gio);
  Serial.print(" Gio ");
  Serial.print(phut);
  Serial.print(" Phut ");
  Serial.print(giay);
  Serial.println(" Giay");
}

void loop() {
}
