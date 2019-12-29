// SOS em codigo Morse

int ledPin = 10;

void setup() 
{
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  // 3 pontos
  for(int i=0; i<3; i++)
  {
    digitalWrite(ledPin, HIGH);
    delay(150);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
  delay(100); // 100ms para o intervalo entre letras

  // 3 traços
  for(int i=0; i<3; i++)
  {
    digitalWrite(ledPin, HIGH);
    delay(400);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
  delay(100); // 100ms para o intervalo entre letras

  // 3 pontos
  for(int i=0; i<3; i++)
  {
    digitalWrite(ledPin, HIGH);
    delay(150);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
  delay(5000); // 5 segundos para repetir o sinal de SOS
}
