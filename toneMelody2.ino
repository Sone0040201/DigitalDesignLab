#include "pitches.h"
#define BUTTON 6
// notes in the melody:
int melody[] = {
   NOTE_C4,  NOTE_C4, NOTE_G5,  NOTE_G5, NOTE_A5, NOTE_A5, NOTE_G5
};
int melody2[] = {
  NOTE_F5,  NOTE_F5, NOTE_E5,  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_C5
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

    tone(8, melody[thisNote], noteDuration);
    delay(pauseBetweenNotes);
    noTone(8);

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
 
    tone(8, melody2[thisNote], noteDuration2);
    delay(pauseBetweenNotes);
    noTone(8);
   
    }
    delay(500);
   }
   previousState = presentState;
}
