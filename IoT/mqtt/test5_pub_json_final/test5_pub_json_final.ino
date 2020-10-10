/***************************************************   
  NodeMCU  
****************************************************/   

/************ Including Libraries *************/
#include <ESP8266WiFi.h>   
#include "Adafruit_MQTT.h"   
#include "Adafruit_MQTT_Client.h"   

#include <ArduinoJson.h>

#include <TaskScheduler.h>
void SendData();    // user defined function that we are going to use

#define _TASK_SLEEP_ON_IDLE_RUN   // energy saving mode

Scheduler runner;     // We create the Scheduler that will be in charge of managing the tasks
#define TimeInterval 6

// We create the task indicating that it runs every 3 minutes, forever, and call the SendData function
Task living(TASK_SECOND * TimeInterval , TASK_FOREVER, &SendData);

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
Adafruit_MQTT_Publish livingroom = Adafruit_MQTT_Publish(&mqtt, MQTT_USERNAME "/pi/livingroom");

/*************************** Sketch Code ************************************/   
void MQTT_connect();   

void setup() {   
     Serial.begin(115200);   
     delay(10);   

     runner.addTask(living);   // add the task to the task scheduler
     living.enable();          // activate the task
    
     Serial.println(F("RPi-ESP-MQTT"));   
     // Connect to WiFi access point.   
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
}   
 
 
uint32_t x=0;   
void loop() {   
     MQTT_connect();   
     delay(1000);           //Simple 1 Sec Delay  
     runner.execute();      // It is necessary to run the runner on each loop
} 

void SendData(){
        DynamicJsonDocument doc1(1024);
        JsonArray array1 = doc1.to<JsonArray>();
            JsonObject obj1 = array1.createNestedObject();
//            obj1["id"] = 1;
            obj1["room"] = "livingroom";
            obj1["type"] = "Applaince";
            obj1["device"] = "Fan 1";
            obj1["status"] = "OFF";
            obj1["readings"] = NULL;

            JsonObject obj2 = array1.createNestedObject();
//            obj2["id"] = 2;
            obj2["room"] = "livingroom";
            obj2["type"] = "Applaince";
            obj2["device"] = "LIGHT 1";
            obj2["status"] = "OFF";
            obj2["readings"] = NULL;

       DynamicJsonDocument doc2(1024);
       JsonArray array2 = doc2.to<JsonArray>();
            JsonObject obj3 = array2.createNestedObject();
//            obj3["id"] = 3;
            obj3["room"] = "livingroom";
            obj3["type"] = "Applaince";
            obj3["device"] = "Light 2";
            obj3["status"] = "ON";
            obj3["readings"] = NULL;

            JsonObject obj4 = array2.createNestedObject();
//            obj4["id"] = 4;
            obj4["room"] = "livingroom";
            obj4["type"] = "Applaince";
            obj4["device"] = "Air Conditoner";
            obj4["status"] = "OFF";
            obj4["readings"] = NULL;

      DynamicJsonDocument doc3(1024);
      JsonArray array3 = doc3.to<JsonArray>();
            JsonObject obj5 = array3.createNestedObject();
//            obj5["id"] = 5;
            obj5["room"] = "livingroom";
            obj5["type"] = "Sensor";
            obj5["device"] = "Gas";
            obj5["status"] = "ON";
            obj5["readings"] =  300;

            JsonObject obj6 = array3.createNestedObject();
//            obj6["id"] = 6;
            obj6["room"] = "livingroom";
            obj6["type"] = "Sensor";
            obj6["device"] = "Temperature";
            obj6["status"] = "ON";
            obj6["readings"] =  28.6  ;

      DynamicJsonDocument doc4(1024);
      JsonArray array4 = doc4.to<JsonArray>();
            JsonObject obj7 = array4.createNestedObject();
//            obj7["id"] = 7;
            obj7["room"] = "livingroom";
            obj7["type"] = "Sensor";
            obj7["device"] = "Humidity";
            obj7["status"] = "OFF";
            obj7["readings"] =  52.3;

            JsonObject obj8 = array4.createNestedObject();
//            obj8["id"] = 8;
            obj8["room"] = "livingroom";
            obj8["type"] = "Sensor";
            obj8["device"] = "Smoke";
            obj8["status"] = "ON";
            obj8["readings"] = 265;

// serializing data
      char json_string1[512], json_string2[512], json_string3[700], json_string4[700];
  
      serializeJson(array1, json_string1);  serializeJson(array2, json_string2);
      serializeJson(array3, json_string3);  serializeJson(array4, json_string4);

//      Serial.println(json_string1);  Serial.println(json_string2);
//      Serial.println(json_string3);  Serial.println(json_string4);

// publishing data to livingroom
      bool p1 = livingroom.publish(json_string1); delay(1000);
      bool p2 = livingroom.publish(json_string2); delay(1000);
      bool p3 = livingroom.publish(json_string3); delay(1000);
      bool p4 = livingroom.publish(json_string4); delay(1000);
 
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
