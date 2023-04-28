#define ROW1 5
#define ROW2 4
#define ROW3 A2
#define ROW4 8
#define ROW5 A1
#define ROW6 10
#define ROW7 11
#define ROW8 A4
#define COL1 9
#define COL2 12
#define COL3 7
#define COL4 13
#define COL5 A3
#define COL6 6
#define COL7 3
#define COL8 A0
#define BUTTON 2
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

byte A[8][8] = {
{1,1,1,0,0,1,1,1},
{1,1,1,0,0,1,1,1},
{1,1,0,1,1,0,1,1},
{1,1,0,1,1,0,1,1},
{1,0,1,1,1,1,0,1},
{1,0,0,0,0,0,0,1},
{1,0,1,1,1,1,0,1},
{0,1,1,1,1,1,1,0}};

byte previousState=1, presentState=1, patternNumber=0;
byte incomingByte = 0 ,save;

void setup()
{
  Serial.begin(2400);
  for (byte i = 0; i < sizeof(row); i++) {
    pinMode(row[i], OUTPUT);
  }
  for (byte i = 0; i < sizeof(col); i++) {
    pinMode(col[i], OUTPUT);
  }
  //pinMode(2, INPUT_PULLUP);
}
void loop()
{
  
  if(Serial.available()>0){
    incomingByte = Serial.read();
   }
  if(incomingByte=='c') save = 'c';
  else if(incomingByte=='H') save = 'H';
  else if(incomingByte=='A') save = 'A';
  else save = save;
  if(save=='c') showPattern(circle);
  else if(save=='H') showPattern(H);
  else if(save=='A') showPattern(A);
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
