void setup() {
  Serial.begin(115200);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  printLine();
  float p = calcPower(5, 0.02);
  printLine();
  float t = calcVoltage(12, 2);
  printLine();
  float d = calcCurrent(12, 2);
  printLine();
  float r = calcLedResistor(5, 2, 10);
  printLine();
  float errorPercent = calcErrorPercent(220, 217);
  Serial.println(errorPercent);
  if (errorPercent >= -5 && errorPercent <= 5) {
    Serial.println("Within tolerance");
  }
  else {Serial.println("Out of tolerance");}
}

float calcLedResistor(float supplyV, float ledVf, float currentMa) {
  float resistor = (supplyV - ledVf) / (currentMa / 1000);
  Serial.print("Your LED resistor is: ");
  Serial.print(resistor);
  Serial.println(" ohm");
  return resistor;
}

float calcPower(float V, float I) {
  float power = V * I;
  Serial.print("Your Power is: ");
  Serial.print(power * 1000);
  Serial.println(" mW");
  return power;
}

float calcVoltage(float P, float I) {
  float voltage = P / I;
  Serial.print("Your Voltage is: ");
  Serial.print(voltage * 1000);
  Serial.println(" mV");
  return voltage;
}

float calcCurrent(float P, float V) {
  float current = P / V;
  Serial.print("Your Current is: ");
  Serial.print(current * 1000);
  Serial.println(" mA");
  return current;
}

void printLine() {
  Serial.println("--------------------");
}

void blinkLed(int pin, int blinkTimes, int delayTime) {
  for (int i = 1; i <= blinkTimes; i++) {
    digitalWrite(pin, HIGH);
    delay(delayTime);
    digitalWrite(pin, LOW);
    delay(delayTime);
  }
}

void setUpBlink() {
  Serial.println("Please enter your LED (13 = Red, 12 = Yellow, 11 = Blue): ");
  while (Serial.available() == 0) {}
  int t = Serial.parseInt();
  while (Serial.available() > 0) { Serial.read(); }
  if (t < 11 || t > 13) {
    Serial.println("Your number is invalid!");
    return;
  }

  Serial.println("Please enter how many times you want to blink: ");
  while (Serial.available() == 0) {}
  int b = Serial.parseInt();
  while (Serial.available() > 0) { Serial.read(); }
  if (b <= 0) {
    Serial.println("Your number is invalid!");
    return;
  }

  Serial.println("Please enter the delay (milliseconds): ");
  while (Serial.available() == 0) {}
  int d = Serial.parseInt();
  while (Serial.available() > 0) { Serial.read(); }
  if (d <= 0) {
    Serial.println("Your number is invalid!");
    return;
  }

  blinkLed(t, b, d);
}

void setColor(int red, int yellow, int blue) {
  digitalWrite(13, red);
  digitalWrite(12, yellow);
  digitalWrite(11, blue);
  return;
}

void flushSerial() {
  while (Serial.available() > 0) { Serial.read(); }
  return;
}

float readNumber() {
  while (true) {
    while (Serial.available() == 0) {}
    float t = Serial.parseFloat();
    flushSerial();
    if (t > 0) {
      return t;
    }
    Serial.println("Your number is invalid!");
  }
}
float calcErrorPercent(float nominal, float measured){
  float error = ((measured-nominal)/nominal)*100;
  return error;
}
void loop() {
  Serial.println("Please Enter V: ");
  float t = readNumber();
  Serial.println("Please Enter I:");
  float d = readNumber();
  calcPower(t,d);
}
