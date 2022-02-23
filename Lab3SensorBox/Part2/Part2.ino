void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(A0, INPUT);
}

void loop()
{
  
  int pot_in = analogRead(A0);
  int pot_to_tone = map(pot_in, 0, 1023, 0, 255);
  tone(9, pot_to_tone);
}
