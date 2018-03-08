const int red1=2;
const int green1=3;
const int blue1=4;
const int yellow1=5;
const int yellow2=6;
const int blue2=7;
const int green2=8;
const int red2=9;
void setup() {
  pinMode(red1, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(blue1, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(blue2, OUTPUT);
  pinMode(yellow2, OUTPUT);
}

void loop() {
  digitalWrite(red1, HIGH);
  digitalWrite(red2, HIGH);
  delay(100);
  digitalWrite(green1, HIGH);
  digitalWrite(green2, HIGH);
  delay(100);
  digitalWrite(blue1, HIGH);
  digitalWrite(blue2, HIGH);
  delay(100);
  digitalWrite(yellow1, HIGH);
  digitalWrite(yellow2, HIGH);
  delay(100);
  digitalWrite(yellow1, LOW);
  digitalWrite(yellow2, LOW);
  delay(100);
  digitalWrite(blue1, LOW);
  digitalWrite(blue2, LOW);
  delay(100);
  digitalWrite(green1, LOW);
  digitalWrite(green2, LOW);
  delay(100);
  digitalWrite(red1, LOW);
  digitalWrite(red2, LOW);
  delay(250);
}








