// Day 6 - Ohm's law calculator on the Serial Monitor (115200 baud, "Newline")
// Choose V, I or R (upper or lower case), enter the two known values, get the third.
// Rejects zero and negative values that would divide by zero or make no sense.

String msg01 = "Please chose what value you want to caculate (V, R, I): ";
String msg02 = "Please Enter the Value R: ";
String msg03 = "Please Enter the Value V: ";
String msg04 = "Please Enter the Value I: ";

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println(msg01);
  while (Serial.available() == 0) {}
  char c = Serial.read();
  delay(10);                                         // let the rest of the line arrive
  while (Serial.available() >= 1) { Serial.read(); } // then clear it

  if (c == 'V' || c == 'v') {
    Serial.println(msg02);
    while (Serial.available() == 0) {}
    float R = Serial.parseFloat();
    while (Serial.available() >= 1) { Serial.read(); }
    if (R == 0) {
      Serial.println("This will cause a short ciruit please enter another number!");
    } else if (R < 0) {
      Serial.println("The number is invalid please enter another number!");
    } else {
      Serial.println(msg04);
      while (Serial.available() == 0) {}
      float I = Serial.parseFloat();
      while (Serial.available() >= 1) { Serial.read(); }
      float V = I * R;
      Serial.print("V = ");
      Serial.println(V);
    }
  } else if (c == 'I' || c == 'i') {
    Serial.println(msg02);
    while (Serial.available() == 0) {}
    float R = Serial.parseFloat();
    while (Serial.available() >= 1) { Serial.read(); }
    if (R == 0) {
      Serial.println("This will cause a short ciruit please enter another number!");
    } else if (R < 0) {
      Serial.println("The number is invalid please enter another number!");
    } else {
      Serial.println(msg03);
      while (Serial.available() == 0) {}
      float V = Serial.parseFloat();
      while (Serial.available() >= 1) { Serial.read(); }
      float I = V / R;
      Serial.print("I = ");
      Serial.println(I);
    }
  } else if (c == 'R' || c == 'r') {
    Serial.println(msg04);
    while (Serial.available() == 0) {}
    float I = Serial.parseFloat();
    while (Serial.available() >= 1) { Serial.read(); }
    if (I == 0 || I < 0) {
      Serial.println("The denominator can not be 0");
    } else {
      Serial.println(msg03);
      while (Serial.available() == 0) {}
      float V = Serial.parseFloat();
      while (Serial.available() >= 1) { Serial.read(); }
      float R = V / I;
      Serial.print("R = ");
      Serial.println(R);
    }
  } else {
    Serial.println("The Entered Value is Invalid (V, R, I).");
  }
  delay(1000);
}
