// Resistor pull up - saida alta quando nao pressionado

byte led = 8;
byte button = 2;

void setup() 
{
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  
  digitalWrite(button, HIGH);
}

void loop()
{
  if(digitalRead(button) == HIGH)
  {
    digitalWrite(led, HIGH);
  }
  else
    digitalWrite(led, LOW);
}
