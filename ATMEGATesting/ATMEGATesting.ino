int Output = 17;
bool done = false;
void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!done) {
    pinMode(Output, OUTPUT);
    digitalWrite(Output, HIGH);
    delay(2000);
    digitalWrite(Output, LOW);
    delay(2000);
    done = true;
  }
}
