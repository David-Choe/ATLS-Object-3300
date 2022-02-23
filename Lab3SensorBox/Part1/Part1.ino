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
  //controls potentiometer
  int pot_in = analogRead(A0);
  int pot_to_LED = map(pot_in, 0, 1023, 0, 255);
  analogWrite(9, pot_to_LED);

  //controls pressure sensor
  int press_in = analogRead(A1);
  int press_to_LED = map(press_in, 0, 1023, 0, 255);
  analogWrite(6, press_to_LED);
}
