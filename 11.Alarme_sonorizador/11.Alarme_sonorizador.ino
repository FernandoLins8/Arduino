// Projeto 11 - Alarme sonorizador
// Dica: usar potenciometro para controlar o volume

float sinVal;
int toneVal;
byte buzzerPin = 11;

void setup()
{
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  for(int i=0; i<180; i++)
  {
    sinVal = sin(i * 3.1416 / 180);
    toneVal = 2000 + int(sinVal * 1000);
    tone(buzzerPin, toneVal); // tone(pin, frequency, duration)
    delay(2);
  }
}
