#include "pitches.h"
#define BUTTON 6
// notes in the melody:
int melody[] = {
   NOTE_C4,  NOTE_C4, NOTE_G5,  NOTE_G5, NOTE_A5, NOTE_A5, NOTE_G5
};
int melody2[] = {
  NOTE_F5,  NOTE_F5, NOTE_E5,  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_C5
};
int LED1[] = {
  2,2,7,7,9,9,7
};
int LED2[] = {
  5,5,4,4,3,3,2
};
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  2,2,2,2,2,2,2
};
int noteDurations2[] = {
  2,2,2,2,2,2,2
};
byte presentState=1,previousState = 1;
byte switchSong=0;
void setup() {
  pinMode(BUTTON,INPUT_PULLUP);
  pinMode(9,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
}

void loop() {
   if (switchSong==0)
   {
    for (int thisNote = 0; thisNote < 7; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    int pauseBetweenNotes = noteDuration * 1.30;
    
    presentState = digitalRead(BUTTON);
    if(presentState==0&&previousState == 1)
    {
     switchSong++;
     if(switchSong==2) switchSong=0;
     break;
    }
    digitalWrite(LED1[thisNote],HIGH);
    tone(8, melody[thisNote], noteDuration);
    delay(pauseBetweenNotes);
    noTone(8);
    digitalWrite(LED1[thisNote],LOW);
    }
    delay(500);
   }
   else if(switchSong==1)
   {
    for (int thisNote = 0; thisNote < 7; thisNote++) {
    int noteDuration2 = 1000 / noteDurations2[thisNote];
    int pauseBetweenNotes = noteDuration2 * 1.30;
    presentState = digitalRead(BUTTON);
    if(presentState==0&&previousState == 1)
    {
     switchSong++;
     if(switchSong==2) switchSong=0;
     break;
    }
    digitalWrite(LED2[thisNote],HIGH);
    tone(8, melody2[thisNote], noteDuration2);
    delay(pauseBetweenNotes);
    noTone(8);
    digitalWrite(LED2[thisNote],LOW);
    }
    delay(500);
   }
   previousState = presentState;
}
