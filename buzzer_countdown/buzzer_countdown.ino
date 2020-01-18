// Countdown
// Buzzer will sound after countdown

// Set hours and minutes below
long hours = 0;
long minutes = 1;

/* Convert hours to minutes, sum hours minutes with minutes
 * Convert all to seconds
 * Convert seconds to miliseconds */
long countdownTime = (((hours * 60) + minutes) * 60) * 1000;

byte buzzerPin = 11;

void setup()
{
  pinMode(buzzerPin, OUTPUT);
  delay(countdownTime);
}

void loop()
{
  tone(buzzerPin, 1000);
}
