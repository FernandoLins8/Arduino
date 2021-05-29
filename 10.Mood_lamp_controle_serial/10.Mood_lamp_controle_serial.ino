// Projeto 10 - Mood lamp com controle serial

char buffer[18];
byte red, green, blue;

byte redPin = 11;
byte greenPin = 10;
byte bluePin = 9;

void setup()
{
  Serial.begin(9600); // taxa de transmissão de pulsos por seg
  Serial.flush();
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop()
{
  if(Serial.available() > 0)
  {
    byte index = 0;
    delay(100); // espera o buffer encher

    int numChar = Serial.available();
    if(numChar > 15)
      numChar = 15;

    while(numChar--)
      buffer[index++] = Serial.read();

    splitString(buffer);
  }
}

void splitString(char* data)
{
  Serial.print("Data entered: ");
  Serial.println(data);
  char* parameter;

  // str-token: divide "data" nos tokens dados (" " e ",")
  parameter = strtok (data, " ,");
  while(parameter != NULL)
  {
    setLED(parameter);
    // passando um ponteiro NULL, strtok continua na prox secao da string
    parameter = strtok (NULL, ", ");
  }

  // Limpa o texto e buffers seriais
  for(int i=0; i<16; i++)
    buffer[i] = '\0';
  Serial.flush();
}

void setLED(char* data)
{ 
  if((data[0] == 'r') || (data[0] == 'R'))
  {
    // strtol: string (first arg) para long int, usando base 10
    int Ans = strtol(data+1, NULL, 10);
    Ans = constrain(Ans, 0, 255); // garante que Ans esteja entre 0 e 255
    analogWrite(redPin, Ans);
    Serial.print("Red is set to: ");
    Serial.println(Ans);
  }

  if((data[0] == 'g') || (data[0] == 'G'))
  {
    int Ans = strtol(data+1, NULL, 10);
    Ans = constrain(Ans, 0, 255);
    analogWrite(greenPin, Ans);
    Serial.print("Green is set to: ");
    Serial.println(Ans);
  }

  if((data[0] == 'b') || (data[0] == 'B'))
  {
    int Ans = strtol(data+1, NULL, 10);
    Ans = constrain(Ans, 0, 255);
    analogWrite(bluePin, Ans);
    Serial.print("Blue is set to: ");
    Serial.println(Ans);
  }
}
