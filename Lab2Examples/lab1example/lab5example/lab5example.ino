void setup()
{
  
  pinMode(6, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
  
}

void loop()
{
  
  int sensor = analogRead(A0);
  Serial.println(sensor);
  analogWrite(6, sensor); 


}
