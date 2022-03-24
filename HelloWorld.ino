
int count = 5;
void setup() {
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, INPUT);
  Serial.begin(9600);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
}

void loop() {
  int button = digitalRead(9);
  if(button == HIGH){
      digitalWrite(count, LOW);
      count++;
      if(count == 8){count = 5;}
      digitalWrite(count, HIGH);
  }
   delay(1000);
}
