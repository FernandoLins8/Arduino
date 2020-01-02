// Projeto 8 - Mood lamp, cores do arco-iris

float RGB1[3];
float RGB2[3];
float INC[3];

byte red, green, blue;

byte redPin = 11;
byte greenPin = 10;
byte bluePin = 9;

// Cada posicao representa uma cor (ex.: 1 laranja (255, 127, 0))
byte current = 0;
byte redRainbow[] = {255, 255, 255, 0, 0, 46, 139};
byte greenRainbow[] = {0, 127, 255, 255, 0, 43, 0};
byte blueRainbow[] = {0, 0, 0, 0, 255, 95, 255};

void setup()
{
  // Valor inicial
  RGB1[0] = 0;
  RGB1[1] = 0;
  RGB1[2] = 0;
  
  // Valor final (transição de RGB1 para RGB2)
  RGB2[0] = redRainbow[0];
  RGB2[1] = greenRainbow[0];
  RGB2[2] = blueRainbow[0];
}

void loop()
{
  // Incremento, avançar de RGB1 para RGB2 em 256 passos
  for(int i=0; i<3; i++)
    INC[i] = (RGB1[i] - RGB2[i]) / 256;
  
  for(int i=0; i<256; i++)
  {
    red = int(RGB1[0]);
    green = int(RGB1[1]);
    blue = int(RGB1[2]);

    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(bluePin, blue);
    delay(5);
  
    RGB1[0] -= INC[0];
    RGB1[1] -= INC[1];
    RGB1[2] -= INC[2];
  }

  // Nova cor
  byte newColor = current + 1;
  if(newColor == 7) newColor = 0;

  RGB2[0] = redRainbow[newColor];
  RGB2[1] = greenRainbow[newColor];
  RGB2[2] = blueRainbow[newColor];

  current = newColor;
  delay(2000);
}
