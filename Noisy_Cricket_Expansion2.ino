const int speakerPin=12;
const int sensorpin1=2;
const int sensorpin2=4;

const int highChirp=20;
const int lowChirp=14;

const int chirpCycle=70;
const int chirpPause=8;
const int numChirps=10;
const int midChirp=150;
const int skittish=5000;

int state1;
int laststate1;

int state2;
int laststate2;

void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(sensorpin1, INPUT);
  pinMode(sensorpin2, INPUT);
}

void loop() {
  state1=digitalRead(sensorpin1);
  state2=digitalRead(sensorpin2);
  if (state1!=laststate1 || state2!=laststate2){
    digitalWrite(speakerPin, HIGH);
    delay(100);
    digitalWrite(speakerPin, LOW);
    delay(500);
    digitalWrite(speakerPin, HIGH);
    delay(100);
    digitalWrite(speakerPin, LOW);
    delay(400);
    digitalWrite(speakerPin, HIGH);
    delay(100);
    digitalWrite(speakerPin, LOW);
    delay(300);
    digitalWrite(speakerPin, HIGH);
    delay(100);
    digitalWrite(speakerPin, LOW);
    delay(200);
    digitalWrite(speakerPin, HIGH);
    delay(100);
    digitalWrite(speakerPin, LOW);
    delay(100);
  }
  laststate1=state1;
  laststate2=state2;
}
