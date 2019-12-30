// Projeto 6 - Iluminação sequencial com LEDs, delay controlado pelo potenciometro

byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
byte potPin = 2;;
byte currentLed = 9;
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
  delay(ledDelay);
  digitalWrite(ledPin[currentLed], LOW);
  digitalWrite(ledPin[0], HIGH);
  currentLed -= 1;

  if(currentLed == 0)
  {
    delay(ledDelay * 2);
    digitalWrite(ledPin[0], LOW);
    currentLed = 9;
    delay(1000);
  }
}
