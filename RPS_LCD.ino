//Define lcd library
#include <LiquidCrystal.h>

//these are constants for input
const int rock=2;
const int paper=4;
const int scissors=3;

const int start_button=11;

int win;
int lose;
int tie;

float counter;

//defines pins for lcd screen
LiquidCrystal lcd(5, 6, 7, 8, 9, 10);

//makes all LED's input or output
void setup(){
  lcd.begin(16, 2);
  pinMode(rock, INPUT);
  pinMode(paper, INPUT);
  pinMode(scissors, INPUT);
  pinMode(start_button, INPUT);
  Serial.begin(9600);
}

void loop(){
  //reads all buttons
  win=0;
  lose=0;
  tie=0;
  lcd.setCursor(0, 0);
  lcd.print("  Press Button  "); 
  lcd.setCursor(0, 1);
  lcd.print("    To Start    ");
  int button_read=digitalRead(start_button);
  if (button_read==LOW){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  Rock, Paper,  ");
  lcd.setCursor(0, 1);
  lcd.print("   or Scissors  ");
  for (int i=1; i<4; i++){
  int rockbutton=digitalRead(rock);
  int paperbutton=digitalRead(paper);
  int scissorsbutton=digitalRead(scissors);
  while (rockbutton==HIGH && paperbutton==HIGH && scissorsbutton==HIGH){
  rockbutton=digitalRead(rock);
  paperbutton=digitalRead(paper);
  scissorsbutton=digitalRead(scissors);
  }
    lcd.clear();
    int rps=random(1, 4);//generates a random number and turns on LED based on that number
    if (rps==1){
      lcd.setCursor(0,0);
      lcd.print("      GAME      ");
      lcd.setCursor(0,1);
      lcd.print("       ");
      lcd.print(i, DEC);
      lcd.print("        ");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("    Bot plays   ");
      lcd.setCursor(0, 1);
      lcd.print("      Rock      ");
      delay(1000);
    }
    else if (rps==2){
      lcd.setCursor(0,0);
      lcd.print("      GAME      ");
      lcd.setCursor(0,1);
      lcd.print("       ");
      lcd.print(i, DEC);
      lcd.print("        ");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("    Bot plays   ");
      lcd.setCursor(0, 1);
      lcd.print("      Paper     ");
      delay(1000);
    }
    else if (rps==3){
      lcd.setCursor(0,0);
      lcd.print("      GAME      ");
      lcd.setCursor(0,1);
      lcd.print("       ");
      lcd.print(i, DEC);
      lcd.print("        ");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("    Bot plays   ");
      lcd.setCursor(0, 1);
      lcd.print("    Scissors    ");
      delay(1000);
    }

    if (rockbutton==LOW && rps==1){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("       YOU      ");
      lcd.setCursor(0, 1);
      lcd.print("       TIE      ");
      delay(1000);
      tie++;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Rock, Paper,  ");
      lcd.setCursor(0, 1);
      lcd.print("   or Scissors  ");
    }
    else if (rockbutton==LOW && rps==2){//All the ways RPS can go and what LED's need to be turned on based on that
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("       YOU      ");
      lcd.setCursor(0, 1);
      lcd.print("      LOSE      ");
      delay(1000);
      lose++;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Rock, Paper,  ");
      lcd.setCursor(0, 1);
      lcd.print("   or Scissors  ");
    }
    else if (rockbutton==LOW && rps==3){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("       YOU      ");
      lcd.setCursor(0, 1);
      lcd.print("       WIN      ");
      delay(1000);
      win++;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Rock, Paper,  ");
      lcd.setCursor(0, 1);
      lcd.print("   or Scissors  ");
    }
    else if (paperbutton==LOW && rps==1){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("       YOU      ");
      lcd.setCursor(0, 1);
      lcd.print("       WIN      ");
      delay(1000);
      win++;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Rock, Paper,  ");
      lcd.setCursor(0, 1);
      lcd.print("   or Scissors  ");
    }
    else if (paperbutton==LOW && rps==2){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("       YOU      ");
      lcd.setCursor(0, 1);
      lcd.print("       TIE      ");
      delay(1000);
      tie++;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Rock, Paper,  ");
      lcd.setCursor(0, 1);
      lcd.print("   or Scissors  ");
    }
    else if (paperbutton==LOW && rps==3){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("       YOU      ");
      lcd.setCursor(0, 1);
      lcd.print("      LOSE      ");
      delay(1000);
      lose++;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Rock, Paper,  ");
      lcd.setCursor(0, 1);
      lcd.print("   or Scissors  ");
    }
    else if (scissorsbutton==LOW && rps==1){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("       YOU      ");
      lcd.setCursor(0, 1);
      lcd.print("      LOSE      ");
      delay(1000);
      lose++;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Rock, Paper,  ");
      lcd.setCursor(0, 1);
      lcd.print("   or Scissors  ");
    }
    else if (scissorsbutton==LOW && rps==2){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("       YOU      ");
      lcd.setCursor(0, 1);
      lcd.print("       WIN      ");
      delay(1000);
      win++;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Rock, Paper,  ");
      lcd.setCursor(0, 1);
      lcd.print("   or Scissors  ");
    }
    else if (scissorsbutton==LOW && rps==3){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("       YOU      ");
      lcd.setCursor(0, 1);
      lcd.print("       TIE      ");
      delay(1000);
      tie++;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Rock, Paper,  ");
      lcd.setCursor(0, 1);
      lcd.print("   or Scissors  ");
    }
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  Win=");
  lcd.print(win, DEC);
  lcd.print(" Lose=");
  lcd.print(lose, DEC);
  lcd.print("   ");
  lcd.setCursor(0, 1);
  lcd.print("     Tie=");
  lcd.print(tie, DEC);
  lcd.print("      ");
  delay(2000);
  if (win>1){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("       YOU      ");
    lcd.setCursor(0, 1);
    lcd.print("       WIN!     ");
    delay(2000);
  }
  else if(lose>1){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("       YOU      ");
    lcd.setCursor(0, 1);
    lcd.print("      LOSE      ");
    delay(2000);
  }
  else if (tie>1){
    if (win==1){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("       YOU      ");
      lcd.setCursor(0, 1);
      lcd.print("       WIN!     ");
      delay(2000); 
    }
    else if (lose==1){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("       YOU      ");
      lcd.setCursor(0, 1);
      lcd.print("      LOSE      ");
      delay(2000);
    }
    else{
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("       YOU      ");
      lcd.setCursor(0, 1);
      lcd.print("       TIE      ");
      delay(2000);
    } 
  }
  if (tie==1 && lose==1 && win==1){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("       YOU      ");
      lcd.setCursor(0, 1);
      lcd.print("       TIE      ");
      delay(2000);  
  }
  }  
   
}
















