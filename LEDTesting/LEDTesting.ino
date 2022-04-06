int Button = 2;
int LED = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(Button, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(Button) == LOW) {
    digitalWrite(LED, HIGH);
    Serial.println("pressed");
  }
  else {
    digitalWrite(LED, LOW);
    Serial.println("waiting");
  }
  delay(1000);
}
