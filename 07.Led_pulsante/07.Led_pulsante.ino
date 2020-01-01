// Projeto 7 - Luz do LED varia ao invés de simplesmente acender e apagar.

byte ledPin = 9; // Pino PWM
byte ledVal;
float sinVal;

void setup()
{
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  // brilho do LED acompanha uma onda senoidal
  for(int i=0; i<180; i++)
  {
    // converte graus para radianos, obtém o valor do seno
    sinVal = (sin(i * (3.1416 / 180)));
    ledVal = int(sinVal * 255);
    analogWrite(ledPin, ledVal);
    delay(10);
  }
}
