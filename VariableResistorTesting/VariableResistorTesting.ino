int VariableResistor = A5;
float currRes = 0;
float prevRes = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(VariableResistor, INPUT);
  Serial.begin(9600);
}

void loop() {
  currRes = analogRead(VariableResistor);
  if (currRes != prevRes) {
    Serial.println("Pass");
  }
  // put your main code here, to run repeatedly:
  prevRes = analogRead(VariableResistor);
  delay(2000);
}
