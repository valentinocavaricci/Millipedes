#include <DFRobotDFPlayerMini.h>

DFRobotDFPlayerMini player;

enum State {
  IDLE,
  PHASE1,
  PHASE2,
  PHASE3
};

State currentState = IDLE;

const int buttonPin = 2;
const int greenLED = 13;
const int exteriorRedLED = 12;
const int interiorRedLED = 11;
const int uvLED = 9;

bool lastButtonState = HIGH;
bool audioReady = false;
unsigned long stateStartTime = 0;

const unsigned long phase1Time = 30000;   
const unsigned long phase2Time = 60000;   
const unsigned long phase3Time = 30000;   

void stopAudio() {
  if (audioReady) {
    player.stop();
  }
}

void playTrack(int trackNumber) {
  if (audioReady) {
    player.stop();
    delay(200);
    player.play(trackNumber);
  }
}

void setIdleState() {
  digitalWrite(greenLED, HIGH);
  digitalWrite(exteriorRedLED, LOW);
  digitalWrite(interiorRedLED, HIGH);
  digitalWrite(uvLED, LOW);

  stopAudio();
  Serial.println("IDLE");
}

void setPhase1() {
  digitalWrite(greenLED, LOW);
  digitalWrite(exteriorRedLED, HIGH);
  digitalWrite(interiorRedLED, HIGH);
  digitalWrite(uvLED, LOW);

  playTrack(1);   
  Serial.println("PHASE1");
}

void setPhase2() {
  digitalWrite(greenLED, LOW);
  digitalWrite(exteriorRedLED, HIGH);
  digitalWrite(interiorRedLED, LOW);
  digitalWrite(uvLED, LOW);

  playTrack(2);  
  Serial.println("PHASE2");
}

void setPhase3() {
  digitalWrite(greenLED, LOW);
  digitalWrite(exteriorRedLED, HIGH);
  digitalWrite(interiorRedLED, LOW);
  digitalWrite(uvLED, HIGH);

  playTrack(3);  
  Serial.println("PHASE3");
}

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(greenLED, OUTPUT);
  pinMode(exteriorRedLED, OUTPUT);
  pinMode(interiorRedLED, OUTPUT);
  pinMode(uvLED, OUTPUT);

  delay(2000);
  Serial.println("Starting system...");

  if (player.begin(Serial1)) {
    audioReady = true;
    player.volume(29);   
    Serial.println("DFPlayer detected");
  } else {
    Serial.println("DFPlayer NOT detected ! lights only");
  }

  setIdleState();
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  if (currentState == IDLE && buttonState == LOW && lastButtonState == HIGH) {
    currentState = PHASE1;
    stateStartTime = millis();
    setPhase1();
  }

  unsigned long elapsed = millis() - stateStartTime;

  switch (currentState) {
    case PHASE1:
      if (elapsed >= phase1Time) {
        currentState = PHASE2;
        stateStartTime = millis();
        setPhase2();
      }
      break;

    case PHASE2:
      if (elapsed >= phase2Time) {
        currentState = PHASE3;
        stateStartTime = millis();
        setPhase3();
      }
      break;

    case PHASE3:
      if (elapsed >= phase3Time) {
        currentState = IDLE;
        setIdleState();
      }
      break;

    case IDLE:
      break;
  }

  lastButtonState = buttonState;
}