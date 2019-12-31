// Projeto 8 - Mood lamp

float RGB1[3];
float RGB2[3];
float INC[3];

byte red, green, blue;

byte redPin = 11;
byte greenPin = 10;
byte bluePin = 9;

void setup()
{
  randomSeed(analogRead(0));

  // Valor inicial
  RGB1[0] = 0;
  RGB1[1] = 0;
  RGB1[2] = 0;

  // Valor final (transição de RGB1 para RGB2)
  RGB2[0] = random(256);
  RGB2[1] = random(256);
  RGB2[2] = random(256);
}

void loop()
{
  randomSeed(analogRead(0));

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
    delay(10);
  
    RGB1[0] -= INC[0];
    RGB1[1] -= INC[1];
    RGB1[2] -= INC[2];
  }

  // Novo valor para cor
  for(int i=0; i<3; i++)
  {
    /* Numero aleatorio entre 0 e 555 (255 + 300) subtraindo 300.
     * Serão 300 chances em 556 de obter um negativo, 
     * criando uma tendencia para os outros dois canais de cores.
     * (Evitando tons pastéis).
     */
    RGB2[i] = random(556)-300;

    // Forma sem tendencia
    //RGB2[i] = random(256);
    
    // Restringe RGB2 (0 <= RGB2[i] <= 255)
    RGB2[i] = constrain(RGB2[i], 0, 255);
    delay(10);
  }
}
