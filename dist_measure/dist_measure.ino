// Medidor de Distancia em cm
// utilizando Sensor de Distancia Ultrasonico HC-SR04

byte trigPin = 12;
byte echoPin = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned long temp = pulseIn(echoPin, HIGH);
  unsigned distance = temp / 58;

  // Printa distancia no Monitor Serial
  Serial.print("Distancia em cm: ");
  Serial.println(distance);
  delay(500);
}
