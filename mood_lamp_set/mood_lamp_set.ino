// Mood Lamp Set - possible to choose color setting colors array

byte redPin = 11;
byte greenPin = 10;
byte bluePin = 9;

// 0, 255, 204
// 28, 12, 173
// 255, 0, 140
// 217, 0, 255
// 255, 255, 0

byte colors[] = {28, 12, 173};
byte red = colors[0];
byte green = colors[1];
byte blue = colors[2];

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop()
{ 
  red = colors[0];
  green = colors[1];
  blue = colors[2];

  fade();
}

void fade()
{
  for(int i=255; i>=0; i--)
  {
    turnOnLights();
    if(red != 0) red -= 1;
    if(green != 0) green -= 1;
    if(blue != 0) blue -= 1;

    if(red == green && green ==  blue && blue ==  0) break; // RGB == (0, 0, 0)
    
    delay(20);
  }
}

void turnOnLights()
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

void turnOffLights()
{
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
}
