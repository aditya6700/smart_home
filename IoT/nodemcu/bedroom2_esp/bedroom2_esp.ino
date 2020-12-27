#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include "config.h"
#include <DHT.h>

WiFiClient espClient;
PubSubClient client(espClient);

float Temperature();
void SendData(); 
void SubData();

int Sensor1();
int Sensor2();

unsigned long previousMillis_pub = 0;   
const long period_pub = 10000;         

#define DHTPIN 5 //D1         //pin where the dht11 is connected   
DHT dht(DHTPIN, DHT11);

void setup() {
      Serial.begin(115200);
      setup_wifi();
      client.setServer(mqtt_server, 1883);
      client.setCallback(callback);
        dht.begin();
       
}
 float Temperature(){
  float temp = dht.readTemperature();
  return temp;
}
void setup_wifi() {
      delay(10);
       
      Serial.println();
      Serial.print("Connecting to ");
      Serial.println(ssid);
    
      WiFi.begin(ssid, password);
    
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
      }
    
      Serial.println("");
      Serial.println("WiFi connected");
      Serial.println("IP address: ");
      Serial.println(WiFi.localIP());
}


void callback(char* topic, byte* payload, unsigned int length) {
//      Serial.print("message arrived from: ");
      Serial.println(topic);
      if (strcmp(topic,"/esp8266/bedroom2")==0){
//          Serial.print(F("Got: "));   
          char *mydata = (char*)payload;
//          Serial.println(mydata);

            DynamicJsonDocument doc(200);   
            DeserializationError error = deserializeJson(doc, mydata);    
            
            if (error) {
              Serial.print("deserializeJson() failed: ");
              Serial.println(error.c_str());
              return;
            }
            
            String DeviceType = doc["device"];
            uint8_t DeviceStatus = doc["status"];
            if ( DeviceType == "Light 1" )
//                digitalWrite(LIGHT1,DeviceStatus); 
                    Serial.println("light 1");
            else if ( DeviceType == "Light 2" )
//                digitalWrite(LIGHT2,DeviceStatus);
                    Serial.println("light 2");
            else if ( DeviceType == "Fan 1" )
//                digitalWrite(FAN1,DeviceStatus);
                    Serial.println("fan 1");
            else if ( DeviceType == "Air Conditioner" )
//                digitalWrite(AC,DeviceStatus);
                     Serial.println("fan 2");
      }
      
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");
      client.subscribe("/esp8266/bedroom2");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}


void loop() {

      if (!client.connected()) {
        reconnect();
      }
      client.loop();
      unsigned long currentMillis = millis();
      if(currentMillis - previousMillis_pub >= period_pub){
         previousMillis_pub = currentMillis;
         SendData();
//        Serial.println(" ");
       }
}

int Sensor1(){
  int sensor_1 = random(200, 900);
  return sensor_1;
}

int Sensor2(){
  int sensor_2 = random(400, 1200);
  return sensor_2;
}

void SendData(){
        DynamicJsonDocument doc1(1024);
        JsonArray array1 = doc1.to<JsonArray>();
            JsonObject obj1 = array1.createNestedObject();
            obj1["fan1"]     =  "ON";
            obj1["fan2"]     =  "OFF";
            obj1["light1"]   =  "OFF";
            obj1["light2"]   =  "ON";
            obj1["AC"]       =  "OFF";

            JsonObject obj2 = array1.createNestedObject();
            obj2["temparature"]   =  Sensor2();
            obj2["humidity"]      =  Sensor1();
            obj2["gas"]           =  Sensor2();
            obj2["oxygen"]        =  Sensor1();
            obj2["motion"]        =  Temperature();

      // serializing data
      char json_string1[512];
      serializeJson(array1, json_string1);  
      
      Serial.println(json_string1); 

     // publishing data to bedroom2
      bool p1 = client.publish("/pi/bedroom2", json_string1); 
      
      if(p1)
        Serial.println("Published");
      delay(20);
}
