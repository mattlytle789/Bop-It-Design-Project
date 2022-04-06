int Button = 2;

void setup() {
  pinMode(Button, INPUT_PULLUP);

  // For printing variable values
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(Button) == LOW) {
    Serial.println("pressed");
  }
  else {
    Serial.println("waiting");
  }
  delay(1000);
}
