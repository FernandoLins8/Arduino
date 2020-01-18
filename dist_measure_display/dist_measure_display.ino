// Medidor de Distancia (cm)
// input: Sensor de Distancia Ultrasonico HC-SR04
// output: Display de sete segmentos (um digito)

/* Digito mostrado no display:
 * 0 (dist >= 0 e dist < 10)
 * 1 (dist >= 10 e dist < 20)
 * 2 (dist >= 20 e dist < 30)
 * ...
 * 9 (dist >= 90)
 */

byte pinNum[] = {13, 12, 11, 10, 9, 8, 7, 6};

byte numsDisplay[][8] = 
{{1, 1, 1, 1, 1, 1, 0, 0},
 {0, 1, 1, 0, 0, 0, 0, 0},
 {1, 1, 0, 1, 1, 0, 1, 0},
 {1, 1, 1, 1, 0, 0, 1, 0},
 {0, 1, 1, 0, 0, 1, 1, 0},
 {1, 0, 1, 1, 0, 1, 1, 0},
 {1, 0, 1, 1, 1, 1, 1, 0},
 {1, 1, 1, 0, 0, 0, 0, 0},
 {1, 1, 1, 1, 1, 1, 1, 0},
 {1, 1, 1, 1, 0, 1, 1, 0}};

byte trigPin = 2;
byte echoPin = 3;

void setup()
{
  for(byte i=0; i<8; i++)
    pinMode(pinNum[i], OUTPUT); 

  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  int distance = getDistance();

  int temp = distance/10;
  Serial.println(temp);
  if(temp > 9)
    displayNumber(9);
  else
    displayNumber(temp);

  delay(500);
  clearDisplay();
}

unsigned getDistance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned long temp = pulseIn(echoPin, HIGH);
  unsigned distance = temp / 58;

  Serial.print("Distancia em cm: ");
  Serial.println(distance);

  return distance;  
}

void displayNumber(byte num)
{
  for(byte i=0; i<8; i++)
  {
    if(numsDisplay[num][i] == 1)
    {
      digitalWrite(pinNum[i], HIGH);   
    }
  }
}

void clearDisplay()
{
  for(byte i=0; i<8; i++)
    digitalWrite(pinNum[i], LOW);
}
