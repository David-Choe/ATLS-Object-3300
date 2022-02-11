
const int input_pin = 11;
const int output_pin = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(input_pin, INPUT);
  pinMode(output_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int current_value = digitalRead(input_pin);
  
  if(current_value == HIGH){
    Serial.print("pressed the button");
    // turn the LED on (HIGH is the voltage level)
    digitalWrite(output_pin, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
    // turn the LED off by making the voltage LOW
    digitalWrite(output_pin, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
    
    digitalWrite(output_pin, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)

    digitalWrite(output_pin, LOW);
    delay(1000); // Wait for 1000 millisecond(s)

    digitalWrite(output_pin, HIGH);
    delay(200); // Wait for 1000 millisecond(s)

    digitalWrite(output_pin, LOW);
    delay(200); // Wait for 1000 millisecond(s)

    digitalWrite(output_pin, HIGH);
    delay(200); // Wait for 1000 millisecond(s)

    digitalWrite(output_pin, LOW);
    delay(200); // Wait for 1000 millisecond(s)
  }
}
