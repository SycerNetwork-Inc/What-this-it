#include <SoftwareSerial.h>
#include "DHT.h"

#define DHTPIN 2       // Digital pin connected to DHT22 sensor
#define DHTTYPE DHT22  // DHT 22 (AM2302) type

#define MQ2_PIN A0     // Analog input pin connected to AOUT pin of MQ2 sensor
#define MQ2_DOUT_PIN 3 // Digital input pin connected to DOUT pin of MQ2 sensor
#define FLAME_DOUT_PIN 4 // Digital input pin connected to DOUT pin of flame sensor

#define THRESHOLD_VALUE 500  // Adjust this value according to your desired gas threshold
#define FLAME_THRESHOLD 500  // Adjust this value according to your desired flame detection threshold

#define RXO 8
#define TXO 9

DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial espSerial(RXO, TXO);  // RX, TX pins for ESP8266 communication

void setup() {
  Serial.begin(9600);
  espSerial.begin(9600);
  dht.begin();
  pinMode(RXO, INPUT);
  pinMode(TXO, OUTPUT);
  pinMode(MQ2_DOUT_PIN, INPUT);
  pinMode(FLAME_DOUT_PIN, INPUT);
}

void loop() {
  float humidity = dht.readHumidity();
  float temperatureC = dht.readTemperature();
  float temperatureF = dht.readTemperature(true);
  float convertedFtoC = (temperatureF - 32) * 5.0 / 9.0;

  int gasSensorValue = analogRead(MQ2_PIN);
  int flameSensorValue = digitalRead(FLAME_DOUT_PIN);
  int digitalValue = digitalRead(MQ2_DOUT_PIN);

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print(" *C ");
  Serial.print(temperatureF);
  Serial.print(" *F\t");
  Serial.print("Gas Sensor Value: ");
  Serial.print(gasSensorValue);
  Serial.print("\t");
  Serial.print("Flame Sensor Value: ");
  Serial.print(flameSensorValue);
  Serial.print("\t");
  Serial.print("Gas Detected: ");
  Serial.print(digitalValue);
  Serial.print("\t");
  Serial.print("Flame Detected: ");
  Serial.println(flameSensorValue);

  espSerial.print("Humidity: ");
  espSerial.print(humidity);
  espSerial.print(" %\t");
  espSerial.print("Temperature: ");
  espSerial.print(temperatureC);
  espSerial.print(" *C ");
  espSerial.print(temperatureF);
  espSerial.print(" *F\t");
  espSerial.print("Gas Sensor Value: ");
  espSerial.print(gasSensorValue);
  espSerial.print("\t");
  espSerial.print("Flame Sensor Value: ");
  espSerial.print(flameSensorValue);
  espSerial.print("\t");
  espSerial.print("Gas Detected: ");
  espSerial.print(digitalValue);
  espSerial.print("\t");
  espSerial.print("Flame Detected: ");
  espSerial.println(flameSensorValue);

  delay(1000);
}
