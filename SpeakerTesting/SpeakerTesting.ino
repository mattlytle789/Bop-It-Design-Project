int Speaker = A3;

void setup() {
  // put your setup code here, to run once:
  pinMode(Speaker, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  tone(Speaker, 3,000);
}
