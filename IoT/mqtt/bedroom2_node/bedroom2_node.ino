/******************** NodeMCU **********************/   

/************ Including Libraries *************/
#include <ESP8266WiFi.h>   
#include "Adafruit_MQTT.h"   
#include "Adafruit_MQTT_Client.h"   
#include <ArduinoJson.h>
//#include <TaskScheduler.h>
#include <DHT.h>

/*************************** Custom Functions Defined ************************************/   
void MQTT_connect();   // mqtt connection 
void SendData();    // user defined function for taaskscheduler
float Humidity();
float Teperature();
int Sensor1();
int Sensor2();

void SubData();
/**************** Task Scheduler *****************/
//Scheduler runner;     // We create the Scheduler that will be in charge of managing the tasks
//#define TimeInterval 3

//Scheduler runner2;     // We create the Scheduler that will be in charge of managing the tasks
//#define TimeInterval2 1

//#define _TASK_SLEEP_ON_IDLE_RUN   // energy saving mode

// We create the task indicating that it runs every 3 minutes, forever, and call the SendData function
//Task living(TASK_MINUTE * TimeInterval , TASK_FOREVER, &SendData);
//Task living1(TASK_SECOND * TimeInterval2 , TASK_FOREVER, &Subdata);

/**************** DHT Sensor *****************/
#define DHTPIN 5 //D1         //pin where the dht11 is connected   
DHT dht(DHTPIN, DHT11);

/************************* WiFi Access Point and MQTT server *********************************/   
#define WLAN_SSID "Area 51"   
#define WLAN_PASS "WF647241BB1"   
#define MQTT_SERVER "192.168.0.193" // static ip address of Raspi
#define MQTT_PORT 1883    
#define MQTT_USERNAME ""   
#define MQTT_PASSWORD ""   

/************ Global State ******************/   
// Create an ESP8266 WiFiClient class to connect to the MQTT server.   
WiFiClient client;   

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, MQTT_SERVER, MQTT_PORT, MQTT_USERNAME, MQTT_PASSWORD);   

/****************************** Feeds ***************************************/   
// Notice MQTT paths for AIO follow the form: <username>/feeds/<feedname>   
Adafruit_MQTT_Publish bedroom2_pub = Adafruit_MQTT_Publish(&mqtt, MQTT_USERNAME "/pi/bedroom2");

// Setup a feed called 'esp8266_con' for subscribing to changes.   
Adafruit_MQTT_Subscribe esp8266_con = Adafruit_MQTT_Subscribe(&mqtt, MQTT_USERNAME "/esp8266/bedroom2");

/**************** Pin Definitions *****************/
#define  LIGHT1  12  // D6  
#define  LIGHT2  13  // D7 
#define  FAN1    14  // D5  
#define  AC      0   // D3  
#define GasPin  A0


unsigned long previousMillis_pub = 0;   
const long period_pub = 120000;         

unsigned long previousMillis_sub = 0;   
const long period_sub = 4000; 

void setup() {   
     Serial.begin(115200);   
     delay(10);   
     
/**************** Pin Setup *****************/
     pinMode(LIGHT1, OUTPUT);
     pinMode(LIGHT2, OUTPUT);
     pinMode(FAN1, OUTPUT);
     pinMode(AC, OUTPUT);   
     pinMode(GasPin,INPUT);
    

     digitalWrite(LIGHT1,  HIGH);
     digitalWrite(LIGHT2,  LOW);
     digitalWrite(FAN1,  HIGH);
     digitalWrite(AC,  HIGH);
     
/**************** Task Scheduler *****************/
//     runner.addTask(living);   // add the task to the task scheduler
//     living.enable();          // activate the task
//     living1.enable();
/**************** DHT Sensor *****************/
     dht.begin();
       
/**************** WiFi Connection *****************/
     Serial.println(F("RPi-ESP-MQTT"));   
     Serial.println(); Serial.println();   
     Serial.print("Connecting to ");   
     Serial.println(WLAN_SSID);   
     WiFi.begin(WLAN_SSID, WLAN_PASS);   
     while (WiFi.status() != WL_CONNECTED) {   
          delay(500);   
          Serial.print(".");   
      }   
     Serial.println();   
     Serial.println("WiFi connected");   
     Serial.println("IP address: "); Serial.println(WiFi.localIP());    

      // Setup MQTT subscription for esp8266_con feed.   
     mqtt.subscribe(&esp8266_con);
}   
 

void loop() {   
     MQTT_connect();   
     unsigned long currentMillis = millis();
     if(currentMillis - previousMillis_sub >= period_sub){
        previousMillis_sub = currentMillis;
        SubData();
     }
     if(currentMillis - previousMillis_pub >= period_pub){
        previousMillis_pub = currentMillis;
        SendData();
     }

} 

void SubData(){
//  Serial.println("entered");
   /**************** MQTT Subscription *****************/
      Adafruit_MQTT_Subscribe *subscription;   
      while ((subscription = mqtt.readSubscription())) {   
        if (subscription == &esp8266_con) {   
//            Serial.println("subcribed!!");
            char *message = (char *)esp8266_con.lastread;   
            Serial.print(F("Got: "));   
            Serial.println(message);   
           
            DynamicJsonDocument doc(200);   // Create a JSON document
            DeserializationError error = deserializeJson(doc, message);    // Deserialize the data
            // parse the parameters we expect to receive (TO-DO: error handling)
              // Test if parsing succeeds.
            if (error) {
              Serial.print("deserializeJson() failed: ");
              Serial.println(error.c_str());
              return;
            }
            
            String DeviceType = doc["device"];
            uint8_t DeviceStatus = doc["status"];
            if ( DeviceType == "Light 1" )
                digitalWrite(LIGHT1,DeviceStatus); 
            else if ( DeviceType == "Light 2" )
                digitalWrite(LIGHT2,DeviceStatus);
            else if ( DeviceType == "Fan 1" )
                digitalWrite(FAN1,(DeviceStatus == 1) ? 0 : 1);
            else if ( DeviceType == "Air Conditioner" )
                digitalWrite(AC,DeviceStatus);
         }   
      }   
   delay(20);
}

float Humidity(){
  float hum = dht.readHumidity();
  return hum;
}

float Temperature(){
  float temp = dht.readTemperature();
  return temp;
}

int Sensor1(){
//  int sensor_1 = random(200, 900);
//  return sensor_1;
  int gasval = analogRead(GasPin);
  return gasval;
}

int Sensor2(){
  int sensor_2 = random(400, 1200);
  return sensor_2;
}

void SendData(){
        DynamicJsonDocument doc1(1024);
        JsonArray array1 = doc1.to<JsonArray>();
            JsonObject obj1 = array1.createNestedObject();
            obj1["room"]     =  "bedroom2";
            obj1["type"]     =  "Applaince";
            obj1["device"]   =  "Fan 1";
            obj1["status"]   =  digitalRead(FAN1)? "ON" : "OFF";
            obj1["readings"] =  NULL;

            JsonObject obj2 = array1.createNestedObject();
            obj2["room"]     =  "bedroom2";
            obj2["type"]     =  "Applaince";
            obj2["device"]   =  "Light 2";
            obj2["status"]   =  digitalRead(LIGHT1)? "ON" : "OFF";
            obj2["readings"] =  NULL;

       DynamicJsonDocument doc2(1024);
       JsonArray array2 = doc2.to<JsonArray>();
            JsonObject obj3 = array2.createNestedObject();
            obj3["room"]     =  "bedroom2";
            obj3["type"]     =  "Applaince";
            obj3["device"]   =  "Light 2";
            obj3["status"]   =  digitalRead(LIGHT2)? "ON" : "OFF";
            obj3["readings"] =  NULL;

            JsonObject obj4 = array2.createNestedObject();
            obj4["room"]     =  "bedroom2";
            obj4["type"]     =  "Applaince";
            obj4["device"]   =  "Air Conditioner";
            obj4["status"]   =  digitalRead(AC) ? "ON" : "OFF";
            obj4["readings"] =  NULL;

      DynamicJsonDocument doc3(1024);
      JsonArray array3 = doc3.to<JsonArray>();
            JsonObject obj5 = array3.createNestedObject();
            obj5["room"]     =  "bedroom2";
            obj5["type"]     =  "Sensor";
            obj5["device"]   =  "Humidity";
            obj5["status"]   =  "ON";
            obj5["readings"] =  Humidity();
            
            JsonObject obj6 = array3.createNestedObject();
            obj6["room"]     =  "bedroom2";
            obj6["type"]     =  "Sensor";
            obj6["device"]   =  "Temperature";
            obj6["status"]   =  "ON";
            obj6["readings"] =  Temperature();

      DynamicJsonDocument doc4(1024);
      JsonArray array4 = doc4.to<JsonArray>();
            JsonObject obj7 = array4.createNestedObject();
            obj7["room"]     =  "bedroom2";
            obj7["type"]     =  "Sensor";
            obj7["device"]   =  "Gas";
            obj7["status"]   =  "ON";
            obj7["readings"] =  Sensor1();


            JsonObject obj8 = array4.createNestedObject();
            obj8["room"]     =  "bedroom2";
            obj8["type"]     =  "Sensor";
            obj8["device"]   =  "Smoke";
            obj8["status"]   =  "ON";
            obj8["readings"] =  Sensor2();

      // serializing data
      char json_string1[512], json_string2[512], json_string3[512], json_string4[512];
  
      serializeJson(array1, json_string1);  serializeJson(array2, json_string2);
      serializeJson(array3, json_string3);  serializeJson(array4, json_string4);

//      Serial.println(json_string1);  Serial.println(json_string2);
//      Serial.println(json_string3);  Serial.println(json_string4);

     // publishing data to bedroom2
      bool p1 = bedroom2_pub.publish(json_string1); delay(1000);
      bool p2 = bedroom2_pub.publish(json_string2); delay(1000);
      bool p3 = bedroom2_pub.publish(json_string3); delay(1000);
      bool p4 = bedroom2_pub.publish(json_string4);  
 
      if( p1 && p2 && p3 && p4)
        Serial.println("published");
      delay(20);

}

// Function to connect and reconnect as necessary to the MQTT server.   
void MQTT_connect() {   
     int8_t ret;   
     // Stop if already connected.   
     if (mqtt.connected()) {   
      return;   
     }   
     Serial.print("Connecting to MQTT... ");   
     uint8_t retries = 3;   
     while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected   
        Serial.println(mqtt.connectErrorString(ret));   
        Serial.println("Retrying MQTT connection in 5 seconds...");   
        mqtt.disconnect();   
        delay(5000); // wait 5 seconds   
        retries--;   
        if (retries == 0) {   
          // basically die and wait for WDT to reset me   
          while (1);   
        }   
     }   
     Serial.println("MQTT Connected!");   
}
