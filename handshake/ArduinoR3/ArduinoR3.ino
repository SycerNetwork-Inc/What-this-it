#include <SoftwareSerial.h>

SoftwareSerial espSerial(11, 10);

void setup() {
  Serial.begin(9600);
  espSerial.begin(9600);
}

void loop() {
  for (int i = 0; i <= 9999999; i++) {
    espSerial.println(i); 
    delay(1);
  }
}
