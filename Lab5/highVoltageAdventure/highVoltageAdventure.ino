  int speedPin = 5;     //controls speed
  int motor1Pin = 3;    //controls direction via H-bridge port 7
  int motor2Pin = 4;    //controls direction via H-bridge port 2

void setup() {
  pinMode(speedPin, OUTPUT);
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
  int pot_in = analogRead(A0);
  int pot_to_FAN = map(pot_in, 0, 1023, 0, 180);
   
  //set the speed
  analogWrite(speedPin, 180);

    if(pot_to_FAN >= 90){
    //turn in one direction
    digitalWrite(motor1Pin, HIGH);
    digitalWrite(motor2Pin, LOW);
  }

  else{
     //turn the other direction
    digitalWrite(motor1Pin, LOW);
    digitalWrite(motor2Pin, HIGH);
  }
}
