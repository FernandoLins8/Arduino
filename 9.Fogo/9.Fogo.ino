// Projeto 9 - Efeito de fogo com LEDs


// Pinos PWM
// (LED vermelho entre dois amarelos)
byte yellowPin1 = 9;
byte redPin = 10;
byte yellowPin2 = 11;

void setup()
{}

void loop()
{
  analogWrite(yellowPin1, random(120) + 136);
  analogWrite(redPin, random(120) + 136);
  analogWrite(yellowPin2, random(120) + 136);
  delay(random(100));
}
