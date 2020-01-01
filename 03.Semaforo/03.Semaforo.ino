int ledDelay = 6000;
int greenPin = 8;
int yellowPin = 9;
int redPin = 10;

void setup()
{
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
}

void loop()
{
  digitalWrite(greenPin, LOW);
  digitalWrite(redPin, HIGH);
  delay(ledDelay);

  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, HIGH);
  delay(ledDelay - 3000);

  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, HIGH);
  delay(ledDelay);
}
