int number;
int state1;
int state2;
int laststate1;
int laststate2;

int RED=13;
int WHITE=12;
int BUTTON1=4;
int BUTTON2=2;

void red_LED()
{
    digitalWrite(RED, HIGH);
    delay(100);
    digitalWrite(RED, LOW);
    /*delay(500);
    digitalWrite(RED, HIGH);
    delay(100);
    digitalWrite(RED, LOW);
    delay(400);
    digitalWrite(RED, HIGH);
    delay(100);
    digitalWrite(RED, LOW);
    delay(300);
    digitalWrite(RED, HIGH);
    delay(100);
    digitalWrite(RED, LOW);
    delay(200);
    digitalWrite(RED, HIGH);
    delay(100);
    digitalWrite(RED, LOW);
    delay(100);*/
}

void white_LED()
{
    digitalWrite(WHITE, HIGH);
    delay(100);
    digitalWrite(WHITE, LOW);
    /*delay(100);
    digitalWrite(WHITE, HIGH);
    delay(100);
    digitalWrite(WHITE, LOW);
    delay(200);
    digitalWrite(WHITE, HIGH);
    delay(100);
    digitalWrite(WHITE, LOW);
    delay(300);
    digitalWrite(WHITE, HIGH);
    delay(100);
    digitalWrite(WHITE, LOW);
    delay(400);
    digitalWrite(WHITE, HIGH);
    delay(100);
    digitalWrite(WHITE, LOW);
    delay(500);*/
}
void setup() 
{
  pinMode(WHITE, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
}

void loop() 
{
  state1=digitalRead(BUTTON1);
  delay(25);
  state2=digitalRead(BUTTON2);
  if (state1!=laststate1)
  {
    number=1;
  }
  if (state2!=laststate2)
  {
    number=2;
  }
  if (state1!=laststate1 & state2!=laststate2)
  {
    number=3;
  }
  switch(number)
  {
    case 1:
    red_LED();
    break;
    
    case 2:
    white_LED();
    break;
    
    case 3:
    red_LED();
    white_LED();
    break;

    default:
    digitalWrite(RED, LOW);
    digitalWrite(WHITE, LOW);
  }
  laststate1=state1;
  laststate2=state2;
}
