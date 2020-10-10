#include <ArduinoJson.h>
#include <DHT.h>

float Humidity();
float Teperature();
int Sensor1();
int Sensor2();

#define  LIGHT1  12  // D6  
#define  LIGHT2  13  // D7 
#define  FAN1    14  // D5  
#define  AC      2   // D4  
#define DHTPIN 0 //D3         //pin where the dht11 is connected   
DHT dht(DHTPIN, DHT11);

void setup() {
    Serial.begin(9600);
      pinMode(LIGHT1, OUTPUT);
     pinMode(LIGHT2, OUTPUT);
     pinMode(FAN1, OUTPUT);
     pinMode(AC, OUTPUT);   

    
dht.begin();

     digitalWrite(LIGHT1,  HIGH);
     digitalWrite(LIGHT2,  LOW);
     digitalWrite(FAN1,  HIGH);
     digitalWrite(AC,  LOW);
}



void loop() {
  
  if (Serial.available() > 0){
    int c = Serial.read();
    if (c == '1'){
//        StaticJsonDocument<1024> doc;
//        JsonArray array = doc.to<JsonArray>();

//        StaticJsonBuffer<1024> JSONbuffer;
//        JsonArray& array = JSONbuffer.createArray();

//        There is one array with 9 elements:JSON_ARRAY_SIZE(9)
//        There are 9 objects with tsixwo pairs:9*JSON_OBJECT_SIZE(6)
        
         DynamicJsonDocument doc1(1024);
        JsonArray array1 = doc1.to<JsonArray>();
            JsonObject obj1 = array1.createNestedObject();
            obj1["room"]     =  "livingroom";
            obj1["type"]     =  "Applaince";
            obj1["device"]   =  "Fan 1";
            obj1["status"]   =  digitalRead(FAN1);
            obj1["readings"] =  NULL;

            JsonObject obj2 = array1.createNestedObject();
            obj2["room"]     =  "livingroom";
            obj2["type"]     =  "Applaince";
            obj2["device"]   =  "Light 2";
            obj2["status"]   =  digitalRead(LIGHT1);
            obj2["readings"] =  NULL;

       DynamicJsonDocument doc2(1024);
       JsonArray array2 = doc2.to<JsonArray>();
            JsonObject obj3 = array2.createNestedObject();
            obj3["room"]     =  "livingroom";
            obj3["type"]     =  "Applaince";
            obj3["device"]   =  "Light 2";
            obj3["status"]   =  digitalRead(LIGHT2);
            obj3["readings"] =  NULL;

            JsonObject obj4 = array2.createNestedObject();
            obj4["room"]     =  "livingroom";
            obj4["type"]     =  "Applaince";
            obj4["device"]   =  "Air Conditoner";
            obj4["status"]   =  digitalRead(AC);
            obj4["readings"] =  NULL;

      DynamicJsonDocument doc3(1024);
      JsonArray array3 = doc3.to<JsonArray>();
            JsonObject obj5 = array3.createNestedObject();
            obj5["room"]     =  "livingroom";
            obj5["type"]     =  "Sensor";
            obj5["device"]   =  "Humidity";
            obj5["status"]   =  "ON";
            obj5["readings"] =  Humidity();
            JsonObject obj6 = array3.createNestedObject();
            obj6["room"]     =  "livingroom";
            obj6["type"]     =  "Sensor";
            obj6["device"]   =  "Temperature";
            obj6["status"]   =  "ON";
            obj6["readings"] =  Temperature();

      DynamicJsonDocument doc4(1024);
      JsonArray array4 = doc4.to<JsonArray>();
            JsonObject obj7 = array4.createNestedObject();
            obj7["room"]     =  "livingroom";
            obj7["type"]     =  "Sensor";
            obj7["device"]   =  "Gas";
            obj7["status"]   =  "ON";
            obj7["readings"] =  Sensor1();


            JsonObject obj8 = array4.createNestedObject();
            obj8["room"]     =  "livingroom";
            obj8["type"]     =  "Sensor";
            obj8["device"]   =  "Smoke";
            obj8["status"]   =  "ON";
            obj8["readings"] =  Sensor2();

      // serializing data
      char json_string1[512], json_string2[512], json_string3[700], json_string4[700];
  
      serializeJson(array1, json_string1);  serializeJson(array2, json_string2);
      serializeJson(array3, json_string3);  serializeJson(array4, json_string4);

      Serial.println(json_string1);  Serial.println(json_string2);
      Serial.println(json_string3);  Serial.println(json_string4);
       
    }
  }
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
  int sensor_1 = random(200, 900);
  return sensor_1;
}

int Sensor2(){
  int sensor_2 = random(400, 1200);
  return sensor_2;
}
