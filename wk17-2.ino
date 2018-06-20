#include "pitches.h"

int melody2[] = {    //高音
  NOTE_E7,NOTE_E7,NOTE_E7,NOTE_C6,NOTE_E7,  NOTE_G7
};
int melody1[] = {
  NOTE_E5,NOTE_E5,NOTE_E5,NOTE_C5,NOTE_E5,  NOTE_G5
};

int noteDurations=150;
int buttonPin=2;
int ledPin=13;
boolean buttonState=LOW;
boolean State=HIGH;
long currenttime,previoustime;
bool check;

void setup() {
pinMode(buttonPin,INPUT);
pinMode(ledPin,OUTPUT);
digitalWrite(buttonPin,LOW);
attachInterrupt(0,int0,RISING);
}


void int0(){
State =!State; 
}

void loop() {
  buttonState = digitalRead(buttonPin);
 if(State==HIGH){
    for (int thisNote = 0; thisNote < 6; thisNote++) {
      buttonState = digitalRead(buttonPin);
      attachInterrupt(0,int0,CHANGE);
      if (State == LOW){goto aa;}
        tone(8, melody1[thisNote], noteDurations);
        previoustime=millis();
        digitalWrite(ledPin,HIGH);
        check=false;
        while(!check){
          currenttime=millis();
          if(currenttime-previoustime>100){
            check=true;
            digitalWrite(ledPin,LOW);
          }
        }
        int pauseBetweenNotes = noteDurations * 1.30;
        if (thisNote==2||thisNote==4){
           delay(pauseBetweenNotes);
           delay(pauseBetweenNotes);
        }
        else if(thisNote==5){
           delay(pauseBetweenNotes*20);
        }
        else delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(8);
      }
 }
if(State==LOW){
      for (int thisNote = 0; thisNote < 6; thisNote++) {
        buttonState = digitalRead(buttonPin);
      attachInterrupt(0,int0,CHANGE);
      if (State == HIGH){goto aa;}
        tone(8, melody2[thisNote], noteDurations);
        previoustime=millis();
        digitalWrite(ledPin,HIGH);
        attachInterrupt(0,int0,CHANGE);
        check=false;
        while(!check){
          currenttime=millis();
          if(currenttime-previoustime>50){
            check=true;
            digitalWrite(ledPin,LOW);
          }
        }
        int pauseBetweenNotes = noteDurations * 1.30;
        if (thisNote==2||thisNote==4){
           delay(pauseBetweenNotes);
           delay(pauseBetweenNotes);
        }
        else if(thisNote==5){
           delay(pauseBetweenNotes*20);
        }
        else delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(8);
      }
    }
    aa:;
}

