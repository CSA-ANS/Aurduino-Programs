// this program turns on 8 LEDs in order and then turns them off backwards
//lines define all the pins
const int red1=2;
const int green1=3;
const int blue1=4;
const int yellow1=5;
const int yellow2=6;
const int blue2=7;
const int green2=8;
const int red2=9;
//function created to turn two pins on 
void pinson(int pin1, int pin2)
{
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  delay(100);
}
// turns two pins off
void pinsoff(int pin1, int pin2)
{
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  delay(100);
}
//make all the pins the correct type
void setup() 
{
  pinMode(red1, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(blue1, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(blue2, OUTPUT);
  pinMode(yellow2, OUTPUT);
}
//runs this again and again
void loop() 
{
  pinson(red1, red2);
  pinson(green1, green2);
  pinson(blue1, blue2);
  pinson(yellow1, yellow2)
  //turns on all the pins
  pinsoff(yellow1, yellow2);
  pinsoff(blue1, blue2);
  pinsoff(green1, green2);
  pinsoff(red1, red2);
  //turns off all the pins going the opposite direction 
}








