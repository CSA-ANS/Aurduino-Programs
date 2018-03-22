#pragma GCC diagnostic error "-Wall"
#pragma GCC diagnostic error "-Werror"
const int rgb[] = {9,10,11};
//makes array with all pin numbers
const int time=200;
//time is constant 
const int switchPin=2;
//defines the tilt switch pin number
void Short(int color){ 
  //Short function
  digitalWrite(color, HIGH);
  delay(time);
  digitalWrite(color, LOW);
  delay(time);
}
void Long(int color){
  //Long function
  digitalWrite(color, HIGH);
  delay(time*3);
  digitalWrite(color, LOW);
  delay(time);
}
void Short_Long(int color){
  //combines them
  Short(color);
  Long(color);
}
void Long_Short(int color){
  //combines them
  Long(color);
  Short(color);
}
void setup() {
  for (int i=0; i<3; i++) pinMode(rgb[i], OUTPUT);
  //makes all the pins in the array outputs
  pinMode(switchPin, INPUT);
  //makes the switch an input
}

void loop() {
  int bounce1=digitalRead(switchPin);
  delay(25);
  int bounce2=digitalRead(switchPin);
//debounces the switch to make sure it is turned off
  while ((bounce1==bounce2)&&(bounce1==LOW)){//while it is closed
    for (int i=0; i<3; i++) digitalWrite(rgb[i], LOW);//turns all LEDs off
    for (int i=0; i<3; i++){//does the Short twice
      Short(9);
    }
    for (int i=0; i<3; i++){//does the Long twice
      Long(9);
    }
    for (int i=0; i<3; i++){//does the Short twice again
      Short(9);
    }
    bounce1=digitalRead(switchPin);
    delay(25);
    bounce2=digitalRead(switchPin);//debpunces the switch again
  }
  Long_Short(11);
  Long_Short(11);
  Short_Long(11);
  Short(11);
  Short_Long(11);
  Long(11);
  Long(11);
  Short(11);
  Short(11);
  Long_Short(11);
  Long(11);
  Long(11);
  delay(time*3);
  Short_Long(11);
  Short(11);
  Short(11);
  Short(11);
  Short(11);
  Long_Short(11);
  Long(11);
  Short(11);
  delay(time*3);
  Short_Long(11);
  delay(time*3);
  Short(11);
  Short_Long(11);
  Short(11);
  Long(11);
  Long(11);
  Long(11);
  Long_Short(11);
  Short_Long(11);
  delay(time*3);
}
