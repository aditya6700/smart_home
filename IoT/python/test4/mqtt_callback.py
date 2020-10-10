import paho.mqtt.client as mqtt
import yaml

livingroom_data, living_subarr = [], []
bedroom1_data, bed1_subarr   = [], []
bedroom2_data, bed2_subarr   = [], []

def on_connect(client, userdata, flags, rc):
    print("Connected with result code " + str(rc))

def on_message(client, userdata, msg):
    print(msg.payload+"received from "+str(msg.topic)+"with QoS "+str(msg.qos))

def on_message_livingroom(client, userdata, msg):
    incData = yaml.safe_load(msg.payload)
    for i in incData:
       living_subarr.append(i)
    leng = len(living_subarr)
    if(leng == 8):
        print("received from "+msg.topic)
        livingroom_data = living_subarr[:]
        del living_subarr[:]
        for i in livingroom_data:
            print(i)

def on_message_bedroom1(client, userdata, msg):
    incData = yaml.safe_load(msg.payload)
    for i in incData:
       bed1_subarr.append(i)
    leng = len(bed1_subarr)
    if(leng == 8):
        print("received from "+msg.topic)
        bedroom1_data = bed1_subarr[:]
        del bed1_subarr[:]
        for i in bedroom1_data:
            print(i)

def on_message_bedroom2(client, userdata, msg):
    incData = yaml.safe_load(msg.payload)
    for i in incData:
       bed2_subarr.append(i)
    leng = len(bed2_subarr)
    if(leng == 8):
        print("received from "+msg.topic)
        bedroom2_data = bed2_subarr[:]
        del bed2_subarr[:]
        for i in bedroom2_data:
            print(i)