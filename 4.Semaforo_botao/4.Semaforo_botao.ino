byte redPin = 12;
byte yellowPin = 11;
byte greenPin = 10;
byte pedRed = 9;
byte pedGreen = 8;
byte button = 2;

int ledDelay = 10000;
unsigned long lastChange;

void setup()
{
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(pedGreen, OUTPUT);
  pinMode(pedRed, OUTPUT);

  pinMode(button, INPUT);
  
  digitalWrite(greenPin, HIGH);
  digitalWrite(pedRed, HIGH);
}

void loop()
{
  if(digitalRead(button) == HIGH)
  {
    unsigned long timePassed = millis() - lastChange;
    if(timePassed < ledDelay)
      delay(ledDelay - timePassed);
    
    delay(5000);
    changeLights();
    lastChange = millis();
  }
}

void changeLights()
{
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, HIGH);
  delay(ledDelay/2);

  digitalWrite(yellowPin, LOW);
  digitalWrite(redPin, HIGH);
  delay(700);
  
  digitalWrite(pedRed, LOW);
  digitalWrite(pedGreen, HIGH);
  delay(ledDelay);

  for(int i=0; i<10; i++)
  {
    digitalWrite(pedGreen, HIGH);
    delay(300);
    digitalWrite(pedGreen, LOW);
    delay(300);
  }

  digitalWrite(pedGreen, LOW);
  digitalWrite(pedRed, HIGH);
  delay(700);
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, HIGH);
}
