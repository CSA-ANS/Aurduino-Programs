//This program is continously blue and gives an SOS when it is shaken or moved
const int rgb[] = {9,10,11};//makes array with all pin numbers
const int time=200;
const int switchPin=2;//defines the tilt switch pin number
//defines pin types
void setup() 
{
  for (int i=0; i<3; i++) pinMode(rgb[i], OUTPUT);
  pinMode(switchPin, INPUT);
}
void dot()
{
  //dot function
  digitalWrite(9, HIGH);
  delay(time);
  digitalWrite(9, LOW);
  delay(time);
}
void dash()
{
  //dash function
  digitalWrite(9, HIGH);
  delay(time*3);
  digitalWrite(9, LOW);
  delay(time);
}
void dot_dash()
{
  //combines them
  dot();
  dash();
}
void dash_dot()
{
  //combines them
  dash();
  dot();
}

void loop() 
{
  //debounces the switch to make sure it is turned off
  int bounce1=digitalRead(switchPin);
  delay(25);
  int bounce2=digitalRead(switchPin);
  while ((bounce1==bounce2)&&(bounce1==LOW))//while it is closed
  {
    for (int i=0; i<3; i++) digitalWrite(rgb[i], LOW);//turns all LEDs off
    for (int i=0; i<3; i++)//does the dot thrice
    {
      dot();
    }
    for (int i=0; i<3; i++)//does the dash thrice
    {
      dash();
    }
    for (int i=0; i<3; i++)//does dot thrice again
    {
      dot();
    }
    bounce1=digitalRead(switchPin);
    delay(25);
    bounce2=digitalRead(switchPin);//debounces the switch again
  }
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);//if it gets out of the while loop it makes it blue
}
