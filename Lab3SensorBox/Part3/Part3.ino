void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(6, OUTPUT);
  pinMode(A1, INPUT);
}

void loop()
{
  //tilt to turn on light
  int sensor = analogRead(A0);
  analogWrite(9, sensor); 

  //pressure used to control sound
  int press_in = analogRead(A1);
  int press_to_TONE = map(press_in, 0, 1023, 0, 10000);
  analogWrite(6, press_to_TONE);
}
