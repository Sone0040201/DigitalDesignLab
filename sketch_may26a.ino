/*************************************************
   Public Constants
 *************************************************/

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978




#define ROW1 5
#define ROW2 4
#define ROW3 A3
#define ROW4 8
#define ROW5 A4
#define ROW6 10
#define ROW7 11
#define ROW8 2
#define COL1 9
#define COL2 12
#define COL3 7  
#define COL4 13
#define COL5 A2
#define COL6 6
#define COL7 3
#define COL8 A5
#define BUTTON A0
#define BUZZER A1
const int row[] = {
  ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7, ROW8
 };

const int col[] = {
  COL1,COL2, COL3, COL4, COL5, COL6, COL7, COL8
 };

byte scan[8][8] = {
{1,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0},
{0,0,0,1,0,0,0,0},
{0,0,0,0,1,0,0,0},
{0,0,0,0,0,1,0,0},
{0,0,0,0,0,0,1,0},
{0,0,0,0,0,0,0,1}
};

byte circle[8][8] = {
{1,1,0,0,0,0,1,1},
{1,0,1,1,1,1,0,1},
{0,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,0},
{0,1,1,1,1,1,1,0},
{1,0,1,1,1,1,0,1},
{1,1,0,0,0,0,1,1}};

byte H[8][8] = {
{1,0,1,1,1,1,0,1},
{1,0,1,1,1,1,0,1},
{1,0,1,1,1,1,0,1},
{1,0,0,0,0,0,0,1},
{1,0,1,1,1,1,0,1},
{1,0,1,1,1,1,0,1},
{1,0,1,1,1,1,0,1},
{1,0,1,1,1,1,0,1}};

long previousTime = 0, presentTime = 0, PauseBetweenNotes = 0;
int thisnote = -1, noteDuration = 0;


// notes in the melody:
int melody[] = {
   NOTE_C5,  NOTE_C5, NOTE_G5,  NOTE_G5, NOTE_A5, NOTE_A5, NOTE_G5
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

void setup()
{
  for (byte i = 0; i < sizeof(row); i++) {
    pinMode(row[i], OUTPUT);
  }
  for (byte i = 0; i < sizeof(col); i++) {
    pinMode(col[i], OUTPUT);
  }
  pinMode(BUTTON,INPUT_PULLUP);
}

byte presentbuttoncheck = 1,  previousbuttoncheck = 1; 
int save = 0;
void loop()
{ 

  while(save == 0)
  {
    for(int i =0; i<7;i++)
    {
     showPattern(circle);
     CheckToPlay();
     presentbuttoncheck = previousbuttoncheck;
     presentbuttoncheck = digitalRead(BUTTON);
     delay(5);
     if( presentbuttoncheck != previousbuttoncheck )
     {
      save = !save;
      break;
     } 
     delay(1);
    }
  }
  while(save == 1)
  {
    for(int i =0; i<7;i++)
    {
     showPattern(H);
     CheckToPlay();
     presentbuttoncheck = previousbuttoncheck;
     presentbuttoncheck = digitalRead(BUTTON);
     delay(5);
     if( presentbuttoncheck != previousbuttoncheck)
     {
      save = !save;
      break;
     } 
     delay(1);
    }
  }
}

void CheckToPlay()
{
  presentTime = millis();
  if(presentTime - previousTime >= PauseBetweenNotes)
  {
    thisnote += 1;
    if(thisnote >= 7)
    {
      thisnote = -1; PauseBetweenNotes = 100;
      previousTime = millis();
    }
    else
    {
      noteDuration = 500/ noteDurations[thisnote];
      if(save == 0) tone(BUZZER,melody[thisnote],noteDuration);
      else if(save == 1) tone(BUZZER,melody2[thisnote],noteDuration);
      PauseBetweenNotes = noteDuration * 1.2;
      previousTime = millis();
    }
  }
}


void showPattern(byte matrix[8][8]){
  for(byte i = 0; i < 8; i++){
    for(byte j = 0; j < 8; j++){
      digitalWrite(row[j], 1 - scan[i][j]);
      digitalWrite(col[j], 1 - matrix[i][j]);
    }
  for(byte j = 0; j < 8; j++){
    digitalWrite(row[j], HIGH);
    digitalWrite(col[j], LOW);
    }
   }
}
