#include <Wire.h>;
#include <Adafruit_Sensor.h>;
#include <Adafruit_ADXL345_U.h>;

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();
//int SDA = A0;
//int SCL = A1;

void setup() {
  // put your setup code here, to run once:
  //pinMode(SDA, INPUT);
  //pinMode(SEL, INPUT);
  Serial.begin(9600);
  if(!accel.begin()){
    Serial.println("No ADXL345 sensor detected");
    while(1);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(readAccelX());
  Serial.println(readAccelY());
  Serial.println(readAccelZ());
  delay(1000);
}

float readAccelX() {
  sensors_event_t event;
  accel.getEvent(&event);
  return event.acceleration.x;
}
float readAccelY() {
  sensors_event_t event;
  accel.getEvent(&event);
  return event.acceleration.y;
}
float readAccelZ() {
  sensors_event_t event;
  accel.getEvent(&event);
  return event.acceleration.z;
}
