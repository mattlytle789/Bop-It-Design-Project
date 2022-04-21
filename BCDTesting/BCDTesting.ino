int bcdA = 7;
int bcdB = 6;
int bcdC = 5; 
int bcdD = 4;
byte BCD[10][4] = {{0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},{0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1},{1,0,0,0},{1,0,0,1}}; // Used to convert the score into a BCD value
int bcdInputs[4] = {bcdD, bcdC, bcdB, bcdA};

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 4; i++) {
    pinMode(bcdInputs[i], OUTPUT);
  }
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    Serial.println(BCD[1][i]);
    digitalWrite(bcdInputs[i], BCD[1][i]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  /*for (int i = 0; i < 4; i++) {
    Serial.println(BCD[02][i]);
    digitalWrite(bcdInputs[i], BCD[2][i]);
  }
  delay(3000);*/
}
