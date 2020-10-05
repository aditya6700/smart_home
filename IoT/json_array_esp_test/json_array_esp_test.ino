#include <ArduinoJson.h>
void setup() {
    Serial.begin(9600);
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
        
        const int capacity = JSON_ARRAY_SIZE(9) + 9*JSON_OBJECT_SIZE(6);
        StaticJsonBuffer<capacity>JSONbuffer;
      
        JsonArray& array = JSONbuffer.createArray();
        
        JsonObject& obj1 = array.createNestedObject();
          obj1["id"] = 1;
          obj1["room"] = "livingroom";
          obj1["type"] = "Applaince";
          obj1["device"] = "Fan 1";
          obj1["status"] = "OFF";
          obj1["readings"] = NULL;

        JsonObject& obj2 = array.createNestedObject();
          obj2["id"] = 2;
          obj2["room"] = "livingroom";
          obj2["type"] = "Applaince";
          obj2["device"] = "Fan 2";
          obj2["status"] = "OFF";
          obj2["readings"] = NULL;

        JsonObject& obj3 = array.createNestedObject();
          obj3["id"] = 3;
          obj3["room"] = "livingroom";
          obj3["type"] = "Applaince";
          obj3["device"] = "Light 1";
          obj3["status"] = "ON";
          obj3["readings"] = NULL;

        JsonObject& obj4 = array.createNestedObject();
        obj4["id"] = 4;
          obj4["room"] = "livingroom";
          obj4["type"] = "Applaince";
          obj4["device"] = "Light 2";
          obj4["status"] = "OFF";
          obj4["readings"] = NULL;

        JsonObject& obj5 = array.createNestedObject();
          obj5["id"] = 5;
          obj5["room"] = "livingroom";
          obj5["type"] = "Applaince";
          obj5["device"] = "Air Conditoner";
          obj5["status"] = "OFF";
          obj5["readings"] =  NULL;

        JsonObject& obj6 = array.createNestedObject();
          obj6["id"] = 6;
          obj6["room"] = "livingroom";
          obj6["type"] = "Sensor";
          obj6["device"] = "Temparature";
          obj6["status"] = "ON";
          obj6["readings"] =  28.6  ;

        JsonObject& obj7 = array.createNestedObject();
          obj7["id"] = 7;
          obj7["room"] = "livingroom";
          obj7["type"] = "Sensor";
          obj7["device"] = "Humidity";
          obj7["status"] = "OFF";
          obj7["readings"] =  52.3;

        JsonObject& obj8 = array.createNestedObject();
          obj8["id"] = 8;
          obj8["room"] = "livingroom";
          obj8["type"] = "Sensor";
          obj8["device"] = "Gas Level";
          obj8["status"] = "ON";
          obj8["readings"] =  "imp";
          
        JsonObject& obj9 = array.createNestedObject();
          obj9["id"] = 9;
          obj9["room"] = "livingroom";
          obj9["type"] = "Sensor";
          obj9["device"] = "Gas Level";
          obj9["status"] = "ON";
          obj9["readings"] =   "imp";

//        forJsonArray, if we want to produce aJSON document out of it, we
//        just need to callJsonArray::printTo():

//        To produce a prettified document, 
//        you just need to use prettyPrintTo()instead ofprintTo():
        
        char JSONmessageBuffer[2048];
//        array.printTo(JSONmessageBuffer, sizeof(JSONmessageBuffer));
        array.prettyPrintTo(JSONmessageBuffer, sizeof(JSONmessageBuffer));
        JsonVariant v = array ;
        String output = v.as<String>();
        Serial.println(output);
       
    }
  }
}
