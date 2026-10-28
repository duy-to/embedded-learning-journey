// Day 4 - Logical operators (&&, ||) and casting
// 1) Sensor error check: a reading outside -40..85 C is invalid (||)
// 2) Classify temperature: Lanh / Mat / Nong
// 3) Leap year: (divisible by 4 AND not by 100) OR divisible by 400
//    Test with 1900 (no), 2000 (yes), 2024 (yes), 2026 (no)
// 4) Average score with (float) cast so 17 / 4 = 4.25, not 4

float sensorTemp = 25;
int year = 2026;
int tong_diem = 17;
int so_bai = 4;

void setup() {
  Serial.begin(115200);
  if (sensorTemp < -40 || sensorTemp > 85) {
    Serial.println("Loi cam bien!!");
  } else {
    Serial.print("Nhiet do bay gio la: ");
    Serial.println(sensorTemp);

    float temp = sensorTemp;
    if (temp < 18) {
      Serial.println("Lanh");
    } else if (temp >= 18 && temp < 30) {
      Serial.println("Mat");
    } else {
      Serial.println("Nong");
    }
  }

  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
    Serial.print("Nam nay la nam nhuan: ");
    Serial.println(year);
  } else {
    Serial.print("Nam nay la nam khong nhuan: ");
    Serial.println(year);
  }

  float diem_trung_binh = (float)tong_diem / so_bai;
  Serial.print("Diem trung binh la: ");
  Serial.println(diem_trung_binh, 2);
}

void loop() {
}
