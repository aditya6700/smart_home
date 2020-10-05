
/***************************************************   
  NodeMCU  
****************************************************/   
#include <ESP8266WiFi.h>   
#include "Adafruit_MQTT.h"   
#include "Adafruit_MQTT_Client.h"   

#include <ArduinoJson.h>
/************************* WiFi Access Point *********************************/   
#define WLAN_SSID "Area 51"   
#define WLAN_PASS "WF647241BB1"   
#define MQTT_SERVER "192.168.0.193" // static ip address  
#define MQTT_PORT 1883    
#define MQTT_USERNAME ""   
#define MQTT_PASSWORD ""   

/************ PIN DEFINITIONS ******************/  
#define LIGHT1 D1  
#define LIGHT2 D2 
#define FAN1   D3  
#define FAN2   D5 
#define AC     D6
/************ Global State ******************/   
// Create an ESP8266 WiFiClient class to connect to the MQTT server.   
WiFiClient client;   
// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.   
Adafruit_MQTT_Client mqtt(&client, MQTT_SERVER, MQTT_PORT, MQTT_USERNAME, MQTT_PASSWORD);   
/****************************** Feeds ***************************************/   
// Setup a feed called 'pi_led' for publishing.   
// Notice MQTT paths for AIO follow the form: <username>/feeds/<feedname>   
Adafruit_MQTT_Publish pi_led = Adafruit_MQTT_Publish(&mqtt, MQTT_USERNAME "/leds/pi");   

// Setup a feed called 'esp8266_con' for subscribing to changes.   
Adafruit_MQTT_Subscribe esp8266_con = Adafruit_MQTT_Subscribe(&mqtt, MQTT_USERNAME "/esp8266/livingroom");
  
/*************************** Sketch Code ************************************/   
void MQTT_connect();   

void setup() {   
     Serial.begin(115200);   
     delay(10);   
     pinMode(LIGHT1, OUTPUT);
     pinMode(LIGHT2, OUTPUT);
     pinMode(FAN1, OUTPUT);
     pinMode(FAN2, OUTPUT);
     pinMode(AC, OUTPUT);   

     digitalWrite(LIGHT1,  LOW);
     digitalWrite(LIGHT2,  LOW);
     digitalWrite(FAN1,  LOW);
     digitalWrite(FAN2,  LOW);
     digitalWrite(AC,  LOW);
 
    
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
     // Setup MQTT subscription for esp8266_con feed.   
     mqtt.subscribe(&esp8266_con);   
}   

uint32_t x=0;   
void loop() {   

     MQTT_connect();   
 
     Adafruit_MQTT_Subscribe *subscription;   
     while ((subscription = mqtt.readSubscription())) {   
      if (subscription == &esp8266_con) {   
        char *message = (char *)esp8266_con.lastread;   
        Serial.print(F("Got: "));   
        Serial.println(message);   
       
          DynamicJsonDocument doc(200);
        // deserialize the data
        DeserializationError error = deserializeJson(doc, message);
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
//              Serial.println( DeviceType);
        else if ( DeviceType == "Fan 1" )
            digitalWrite(FAN1,DeviceStatus);
//              Serial.println(DeviceStatus );
        else if ( DeviceType == "Fan 2" )
            digitalWrite(FAN2,DeviceStatus);
//              Serial.println(DeviceStatus);
        else if ( DeviceType == "Air Conditioner" )
            digitalWrite(AC,DeviceStatus);
//              Serial.println(DeviceType);
      
//          int LIGHT1_status = doc["LIGHT1"];
//          int LIGHT2_status = doc["LIGHT2"];
//          int FAN1_status = doc["FAN1"];
//          int FAN2_status = doc["FAN2"];
//          int AC_status = doc["AC"];
          
          
          
        
         
      }   
    }   
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
