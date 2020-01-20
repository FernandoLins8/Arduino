// IR Remote Control - testing with seven seg display


// IR Remote Library by Ken Shirriff
#include <IRremote.h>

#define ZERO 0xFF9867
#define ONE 0xFFA25D
#define TWO 0xFF629D
#define THREE 0xFFE21D
#define FOUR 0xFF22DD
#define FIVE 0xFF02FD
#define SIX 0xFFC23D
#define SEVEN 0xFFE01F
#define EIGHT 0xFFA857
#define NINE 0xFF906F

#define STAR 0xFF6897
#define HASH 0xFFB04F
 
#define UP 0xFF18E7
#define RIGHT 0xFF5AA5
#define DOWN 0xFF4AB5
#define LEFT 0xFF10EF

#define OK 0xFF38C7


byte pinNum[] = {13, 12, 11, 10, 9, 8, 7, 6};

byte numsDisplay[][8] = 
{{1, 1, 1, 1, 1, 1, 0, 0},
 {0, 1, 1, 0, 0, 0, 0, 0},
 {1, 1, 0, 1, 1, 0, 1, 0},
 {1, 1, 1, 1, 0, 0, 1, 0},
 {0, 1, 1, 0, 0, 1, 1, 0},
 {1, 0, 1, 1, 0, 1, 1, 0},
 {1, 0, 1, 1, 1, 1, 1, 0},
 {1, 1, 1, 0, 0, 0, 0, 0},
 {1, 1, 1, 1, 1, 1, 1, 0},
 {1, 1, 1, 1, 0, 1, 1, 0}};

int receiver = 2;
IRrecv irrecv(receiver);
decode_results results;

void setup()
{
  for(byte i=0; i<8; i++)
    pinMode(pinNum[i], OUTPUT); 

  //Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop()
{
  if (irrecv.decode(&results))
  {
    clearDisplay();

    switch(results.value)
    {
      case ZERO: displayNumber(0);
        break;
      case ONE: displayNumber(1);
        break;
      case TWO: displayNumber(2);
        break;
      case THREE: displayNumber(3);
        break;
      case FOUR: displayNumber(4);
        break;
      case FIVE: displayNumber(5);
        break;
      case SIX: displayNumber(6);
        break;
      case SEVEN: displayNumber(7);
        break;
      case EIGHT: displayNumber(8);
        break;
      case NINE: displayNumber(9);
        break;
    }
    delay(250);
    irrecv.resume();
  }
}

void displayNumber(byte num)
{
  for(byte i=0; i<8; i++)
  {
    if(numsDisplay[num][i] == 1)
    {
      digitalWrite(pinNum[i], HIGH);   
    }
  }
}

void clearDisplay()
{
  for(byte i=0; i<8; i++)
    digitalWrite(pinNum[i], LOW);
}
