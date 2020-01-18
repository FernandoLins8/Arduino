// Seven Segment Display

byte pinNum[] = {13, 12, 11, 10, 9, 8, 7, 6};
int delayTime = 250;

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

void setup()
{
  for(byte i=0; i<8; i++)
    pinMode(pinNum[i], OUTPUT); 
}

void loop()
{
  count();
  countdown();
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

void count()
{
  for(byte num=0; num<10; num++)
  {
    displayNumber(num);
    delay(delayTime);
    clearDisplay();
  }
}

void countdown()
{
  // bytes cannot store negative nums (bug)
  for(int num=9; num>=0; num--)
  {
    displayNumber(num);
    delay(delayTime);
    clearDisplay();
  }
}
