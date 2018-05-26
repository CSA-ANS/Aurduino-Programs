//Define lcd library
#include <LiquidCrystal.h>

//these are constants for input
const int rock=2;
const int paper=4;
const int scissors=3;

//this is the constant for the start button
const int start_button=11;

//these are global variables that count how mnay wins, losses, and ties a person has
int win;
int lose;
int tie;

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
  //makes win, lose, and tie 0
  win=0;
  lose=0;
  tie=0;
  lcd.setCursor(0, 0);
  lcd.print("  Press Button  "); 
  lcd.setCursor(0, 1);
  lcd.print("    To Start    ");//tells them to press the start button
  int button_read=digitalRead(start_button);
  if (button_read==LOW){//waits for them to press it
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  Rock, Paper,  ");
  lcd.setCursor(0, 1);
  lcd.print("   or Scissors  ");//tells them to press rock paper or scissors
  for (int i=1; i<4; i++){//runs three times because it is best of three
  int rockbutton=digitalRead(rock);
  int paperbutton=digitalRead(paper);
  int scissorsbutton=digitalRead(scissors);//reads all three buttons
  while (rockbutton==HIGH && paperbutton==HIGH && scissorsbutton==HIGH){//waits for one to be pressed
  rockbutton=digitalRead(rock);
  paperbutton=digitalRead(paper);
  scissorsbutton=digitalRead(scissors);//reads them again
  }
    lcd.clear();
    int rps=random(1, 4);//generates a random number and turns on LED based on that number
    if (rps==1){
      lcd.setCursor(0,0);
      lcd.print("      GAME      ");
      lcd.setCursor(0,1);
      lcd.print("       ");
      lcd.print(i, DEC);
      lcd.print("        ");//prints what game they are on
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("    Bot plays   ");//says what the bot plays
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
      lcd.print("        ");//prints what game they are on
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("    Bot plays   ");
      lcd.setCursor(0, 1);
      lcd.print("      Paper     ");//says what the bot plays
      delay(1000);
    }
    else if (rps==3){
      lcd.setCursor(0,0);
      lcd.print("      GAME      ");
      lcd.setCursor(0,1);
      lcd.print("       ");
      lcd.print(i, DEC);
      lcd.print("        ");//prints what game they are on
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("    Bot plays   ");
      lcd.setCursor(0, 1);
      lcd.print("    Scissors    ");//says what the bot plays
      delay(1000);
    }
    //the next 9 ifs determine who wins based on what the bot plays and what button the person pressed. Then they print whether you won, lost, or tied. Also adds to variables win, lose, and tie as the game goes on
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
    else if (rockbutton==LOW && rps==2){
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
  delay(2000);//prints how many wins, losses, and ties they had
  if (win>1){//prints whether they won, lost, or tied overall
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
