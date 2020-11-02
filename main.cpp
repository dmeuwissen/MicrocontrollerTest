#include <Arduino.h>
#include <ESP8266WiFi.h>          

#include <DNSServer.h>            
#include <ESP8266WebServer.h>     
#include <WiFiManager.h>          
#include <PubSubClient.h>

WiFiManager wifiManager;
WiFiClient  espClient;
PubSubClient client(espClient);

const char* MQTT_SERVER_ADRESS = "ec2-100-27-12-57.compute-1.amazonaws.com";
const int MQTT_PORT = 1883;
const char* MQTT_USER = "client";
const char* MQTT_PASSWORD = "Cn*8uw9kmnMUjqSXh!BAe&NdwDVmQpWTDTV$V&%aWgjJa5MPFZg9rzvwPb8HPH8X";


String ESP_ID = String(ESP.getChipId()); //Get unique ESP id to use for connecting to the broker and topic.

const int TEMPERATURE_SENSOR_PIN = A0;

//Function used for connecting to the MQTT server.
void connectMQTT()
{
  client.setServer(MQTT_SERVER_ADRESS, MQTT_PORT);
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");

    //connect to the broker and set last will to publish offline when disconnected.
    if (client.connect(ESP_ID.c_str(), MQTT_USER, MQTT_PASSWORD,(ESP_ID + String("/status")).c_str(),2,1,"Offline")) {
      //Publish online when connected.
      client.publish((ESP_ID + String("/status")).c_str(),"Online",true);
 
      Serial.println("connected");  
 
    } else {
 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }
}


float getTemperatureMeasurement()
{
  int analogMeasurement = analogRead(TEMPERATURE_SENSOR_PIN);
  float temperature = (analogMeasurement/ 1024.0) * 3300 / 10; 
  return temperature;
}

void setup() {  
  wifiManager.autoConnect("De Druppel");
  connectMQTT();
}

void loop() {
  float temperature = getTemperatureMeasurement();
  client.publish((ESP_ID + String("/temperature")).c_str(), String(temperature).c_str());
  delay(5000);  
}