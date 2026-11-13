int a = 3;
int b = 7;

void swapValues1(int* x, int* y) {
  int temp = *x;
  *x = *y;
  *y = temp;
  Serial.println(*x);
  Serial.println(*y);
}

void swapValues2(int x, int y) {
  int temp = x;
  x = y;
  y = temp;
  Serial.println(x);
  Serial.println(y);
}
void setup() {
  Serial.begin(115200);
  swapValues2(a, b);
  Serial.println(a);
  Serial.println(b);
  swapValues1(&a, &b);
}

void loop() {
  // put your main code here, to run repeatedly:
}
