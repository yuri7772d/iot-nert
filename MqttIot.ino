#include <WiFi.h>
#include <PubSubClient.h>
#include <Adafruit_BME280.h>

WiFiClient esp; PubSubClient mqtt(esp); Adafruit_BME280 bme;

void setup() {
  WiFi.begin("devops_wifi","bnccitconfig");
  while (!WiFi.isConnected()) delay(100);
  bme.begin(0x76);
  mqtt.setServer("192.168.10.6",1883);
  while (!mqtt.connect("ESP")) delay(500);
}

void loop() {
  if (!mqtt.connected()) mqtt.connect("ESP");
  char buf[80];
  sprintf(buf,"{\"t\":%.1f,\"h\":%.1f,\"p\":%.1f}",bme.readTemperature(),bme.readHumidity(),bme.readPressure()/100);
  mqtt.publish("vecskill",buf);
  delay(2000);
}
