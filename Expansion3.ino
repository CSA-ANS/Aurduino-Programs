const int red1=2;
const int green1=3;
void setup() {
  pinMode(red1, OUTPUT);
  pinMode(green1, OUTPUT);
}

void loop() {
  digitalWrite(red1, HIGH);
  delay(1000);
  digitalWrite(green1, HIGH);
  delay(1000);
  digitalWrite(green1, LOW);
  delay(1000);
  digitalWrite(red1, LOW);
  delay(1000);
}
