// LEDs pulsantes (rgb)

byte ledPin[] = {9, 10, 11}; // PWM only
byte i = 0;

int ledVal;
float sinVal;

void setup()
{
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  pulse(ledPin[i]);
  i += 1;
  if(i > 2) i = 0;
}

void pulse(byte ledPin)
{
  for(int x=0; x<180; x++)
  {
    // converte graus para radianos, obtém o valor do seno
    sinVal = (sin(x * (3.1416 / 180)));
    ledVal = int(sinVal * 255);
    analogWrite(ledPin, ledVal);
    //analogWrite(9, ledVal);
    //analogWrite(10, ledVal);
    //analogWrite(11, ledVal);
    delay(50);
  }
  digitalWrite(ledPin, LOW);
}
