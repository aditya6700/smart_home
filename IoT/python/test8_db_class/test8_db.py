import time
import yaml
import sys
import paho.mqtt.client as mqtt
from pymongo import MongoClient

broker="127.0.0.1"

dic={
        "livingroom":{
            "Fan 1":0,"Light 1":0,"Light 2":0,"Air Conditioner":0,
            "Temperature":0.00,"Humidity":0.00,"Gas":0.00,"Smoke":0.00,
            "Temperaturecount":0 ,"Humiditycount":0 ,"Gascount":0 ,"Smokecount":0
        },
        "bedroom1":{
            "Fan 1":0,"Light 1":0,"Light 2":0,"Air Conditioner":0,
            "Temperature":0.00,"Humidity":0.00,"Gas":0.00,"Smoke":0.00,
            "Temperaturecount":0 ,"Humiditycount":0 ,"Gascount":0 ,"Smokecount":0
        },
        "bedroom2":{
            "Fan 1":0,"Light 1":0,"Light 2":0,"Air Conditioner":0,
            "Temperature":0.00,"Humidity":0.00,"Gas":0.00,"Smoke":0.00,
            "Temperaturecount":0 ,"Humiditycount":0 ,"Gascount":0 ,"Smokecount":0
        }
    }

try:
    client=MongoClient('localhost',27017)
    mydb = client.smartHome
    print("connection with database established successfully")
except Exception as e:
    print("database connection failed",e)

class Room:
    
    loop_count = 0
    
    def __init__(self, finalArr):
        self.finalArr = finalArr
        
    def database_entry(self,rname): 
        print("in database entry")
        try:
            inpDoc={
                "Fan1": dic[rname]["Fan 1"]//60,
                "Light_1":dic[rname]["Light 1"]//60,
                "Light_2":dic[rname]["Light 2"]//60,
                "Air_Conditioner":dic[rname]["Air Conditioner"]//60,
                "Temperature":dic[rname]["Temperature"]/(dic[rname]["Temperaturecount"]+1),
                "Humidity" : dic[rname]["Humidity"]/(dic[rname]["Humiditycount"]+1),
                "Gas": dic[rname]["Gas"]/(dic[rname]["Gascount"]+1),
                "Smoke": dic[rname]["Smoke"]/(dic[rname]["Smokecount"]+1)
            }
            myCollection = mydb[rname]
            myCollection.insert_one(inpDoc)
            self.loop_count=0
            for key,values in dic.items():
                if rname == key:
                    d=dic[key]
                    d.update({}.fromkeys(d,0))
        except Exception as ex:
            print("Error on line{}".format(sys.exc_info()[-1].tb_lineno),(type(ex).__name__,ex))

    def updation(self,room,res):
        print("{} in updation".format(room))
        s=len(res)
        self.loop_count+=1
        try:
            for i in range(0,s):
                room=res[i]["room"]
                if(res[i]["type"] == "Appliance"):
                    if(res[i]["status"] == "ON"): 
                        dic[room][res[i]["device"]]+=60
                elif(res[i]["type"] == "Sensor" and res[i]["readings"] != None):
                    if(res[i]["status"] == "ON"):
                        dic[room][res[i]["device"]]+=float(res[i]["readings"])
                        device_count="{}count".format(res[i]["device"])
                        dic[room][device_count]+=1
            del self.finalArr[:]
            if(self.loop_count>3):
                self.database_entry(room)
        except Exception as ex:
            print("Error on line{}".format(sys.exc_info()[-1].tb_lineno),(type(ex).__name__,ex))

    def print_data(self,room_name,info_list):
        print("in print_data")
        for i in range(0,len(info_list)):
            if i==0:
                type_val="Appliance"
            elif i==1:
                type_val="Sensor"
            
            for key,values in info_list[i].items():
                rec={
                    "room":room_name,
                    "type":type_val,
                    "device":key,
                    "status": ( values if i == 0 else "ON" if (i == 1 and values != None) else "OFF" ),
                    "readings": ( values if i == 1 else None),
                }            
                self.finalArr.append(rec)
        self.updation(room_name,self.finalArr)

    def on_message(self, client, userdata, msg):
        val = msg.topic[4:]           
        incData = yaml.safe_load(msg.payload) 
        self.print_data(val,incData)
                               
livingroom = Room([])
bedroom1 = Room([])
bedroom2 = Room([])

def on_connect(client, userdata, flags, rc):
    print("Connected with result code " + str(rc))

def on_message(client, userdata, msg):
    print(msg.payload+"received from "+str(msg.topic)+"with QoS "+str(msg.qos))

client = mqtt.Client()
client.on_connect = on_connect 
livingarray = client.message_callback_add('/pi/livingroom', livingroom.on_message)
client.message_callback_add('/pi/bedroom1', bedroom1.on_message)
client.message_callback_add('/pi/bedroom2', bedroom2.on_message)
client.on_message = on_message
client.connect(broker, 1883, 60)
client.subscribe('/pi/#')

client.loop_start()
print('Script is running, press Ctrl-C to quit...')

while True:
  button_first=int(input())
  time.sleep(0.02) 
  if button_first == 0  : 
      print('Button pressed!')
      client.publish('/esp8266/livingroom', sendData)