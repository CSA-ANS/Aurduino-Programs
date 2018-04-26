int rock=2;
int paper=4;
int scissors=7;

int rLED=8;
int pLED=12;
int sLED=13;

int winLED=10;
int loseLED=9;
int tieLED=11;

void setup(){
  pinMode(winLED, OUTPUT);
  pinMode(loseLED, OUTPUT);
  pinMode(tieLED, OUTPUT);
  pinMode(rLED, OUTPUT);
  pinMode(pLED, OUTPUT);
  pinMode(sLED, OUTPUT);
  pinMode(rock, INPUT);
  pinMode(paper, INPUT);
  pinMode(scissors, INPUT);
}
void loop(){
  int rockbutton=digitalRead(rock);
  int paperbutton=digitalRead(paper);
  int scissorsbutton=digitalRead(scissors);
  if (rockbutton==HIGH || paperbutton==HIGH || scissorsbutton==HIGH){
    int rps=random(1, 4);
    if (rps==1){
      digitalWrite(rLED, HIGH);
    }
    if (rps==2){
      digitalWrite(pLED, HIGH);
    }
    if (rps==3){
      digitalWrite(sLED, HIGH);
    }
    if (rockbutton==HIGH && rps==1){
      digitalWrite(tieLED, HIGH);
      delay(1000);
      digitalWrite(tieLED, LOW);
      digitalWrite(rLED, LOW);
    }
    if (rockbutton==HIGH && rps==2){
      digitalWrite(loseLED, HIGH);
      delay(1000);
      digitalWrite(loseLED, LOW);
      digitalWrite(rLED, LOW);
    }
    if (rockbutton==HIGH && rps==3){
      digitalWrite(winLED, HIGH);
      delay(1000);
      digitalWrite(winLED, LOW);
      digitalWrite(rLED, LOW);
    }
    if (paperbutton==HIGH && rps==1){
      digitalWrite(winLED, HIGH);
      delay(1000);
      digitalWrite(winLED, LOW);
      digitalWrite(pLED, LOW);
    }
    if (paperbutton==HIGH && rps==2){
      digitalWrite(tieLED, HIGH);
      delay(1000);
      digitalWrite(tieLED, LOW);
      digitalWrite(pLED, LOW);
    }
    if (paperbutton==HIGH && rps==3){
      digitalWrite(loseLED, HIGH);
      delay(1000);
      digitalWrite(loseLED, LOW);
      digitalWrite(pLED, LOW);
    }
    if (scissorsbutton==HIGH && rps==1){
      digitalWrite(loseLED, HIGH);
      delay(1000);
      digitalWrite(loseLED, LOW);
      digitalWrite(sLED, LOW);
    }
    if (scissorsbutton==HIGH && rps==2){
      digitalWrite(winLED, HIGH);
      delay(1000);
      digitalWrite(winLED, LOW);
      digitalWrite(sLED, LOW);
    }
    if (scissorsbutton==HIGH && rps==3){
      digitalWrite(tieLED, HIGH);
      delay(1000);
      digitalWrite(tieLED, LOW);
      digitalWrite(sLED, LOW);
    }
  }
      
    
}
