// Projeto 6 - Iluminação sequencial com LEDs, delay controlado pelo potenciometro

byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
byte potPin = 2;
byte led1Direction = 1;
byte led2Direction = -1;
byte currentLed1 = 0;
byte currentLed2 = 9;
int ledDelay;
unsigned long changeTime;

void setup()
{
  for(int i=0; i<10; i++)
    pinMode(ledPin[i], OUTPUT);
  changeTime = millis();
}

void loop()
{
  ledDelay = analogRead(potPin);
  if((millis() - changeTime) > ledDelay)
  {
    changeLed();
    changeTime = millis();
  }
}

void changeLed()
{
  for(int i=0; i<10; i++)
    digitalWrite(ledPin[i], LOW);

  digitalWrite(ledPin[currentLed1], HIGH);
  digitalWrite(ledPin[currentLed2], HIGH);
  currentLed1 += led1Direction;
  currentLed2 += led2Direction;

  if(currentLed1 == 0 || currentLed1 == 4) led1Direction *= -1;
  if(currentLed2 == 5 || currentLed2 == 9) led2Direction *= -1;
}
