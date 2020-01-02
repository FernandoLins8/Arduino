// Sirene

#define duration 10
int freq = 0;
int buzzerPin = 11;

void setup()
{
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  for(freq = 150; freq < 1800; freq += 1) 
  {
    tone(buzzerPin, freq, duration); 
    delay(1);
  }
  for (freq = 1800; freq > 150; freq -= 1) 
  {
    tone(buzzerPin, freq, duration); 
    delay(1);
  }
}
