// Day 5 (Bai 7) - Phone battery: starts at 100 %, loses 7 % per hour,
// switches off at 20 %. How many hours does it last? (answer: 12 hours)

int pin = 100;       // battery percent
int discharge = 7;   // percent lost per hour
int gio = 0;         // hours

void setup() {
  Serial.begin(115200);
  while (pin > 20) {
    gio++;
    Serial.print(gio);
    Serial.println(" gio:");
    pin -= discharge;
    Serial.print("Con ");
    Serial.print(pin);
    Serial.println("% pin.");
  }
  Serial.print("Dien thoai tat sau: ");
  Serial.print(gio);
  Serial.println(" gio.");
}

void loop() {
}
