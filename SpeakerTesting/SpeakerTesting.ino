#include "Talkie.h"
#include "Vocab_US_Large.h"
#include "Vocab_US_Acorn.h"


Talkie voice;
int Speaker = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(Speaker, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*tone(Speaker, 1,000);
  delay(2000);
  noTone(Speaker);
  delay(2000);*/
  voice.say(spa_THREE);
  delay(1000);
  voice.say(spa_TWO);
  delay(1000);
  voice.say(spa_ONE);
  delay(1000);
  voice.say(spa_START);
  delay(2000);
}
