// Projeto 6 - Iluminação sequencial com LEDs, delay controlado pelo potenciometro

byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
byte potPin = 2;
byte direction = 1;
byte currentLed = 0;
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

  digitalWrite(ledPin[currentLed], HIGH);
  currentLed += direction;

  if(currentLed == 0 || currentLed == 9) direction *= -1;
}
