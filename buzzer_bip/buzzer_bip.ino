byte buzzer = 11;

void setup()
{
  
}

void loop()
{
  tone(buzzer, 1000);
  delay(25);
  noTone(buzzer);
  delay(1000);
}
