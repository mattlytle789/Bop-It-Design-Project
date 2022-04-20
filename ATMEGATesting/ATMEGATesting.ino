int Output = 17;

void setup() {
  // put your setup code here, to run once:
  pinMode(Output, OUTPUT);
  digitalWrite(Output, HIGH);
  delay(2000);
  digitalWrite(Output, LOW);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Output, HIGH);
  delay(2000);
  digitalWrite(Output, LOW);
  delay(2000);
}
