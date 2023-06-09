#include <SoftwareSerial.h>

SoftwareSerial arduinoSerial(D2, D3);

void setup() {
  Serial.begin(9600);
  arduinoSerial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char data = Serial.read();
    arduinoSerial.print(data);
  }
}
