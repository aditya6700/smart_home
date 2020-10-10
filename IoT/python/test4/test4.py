import time
import paho.mqtt.client as mqtt
import yaml
import mqtt_callback as mod

broker="192.168.0.193"

client = mqtt.Client()
client.on_connect = mod.on_connect 
client.message_callback_add('/pi/livingroom', mod.on_message_livingroom)
client.message_callback_add('/pi/bedroom1', mod.on_message_bedroom1)
client.message_callback_add('/pi/bedroom2', mod.on_message_bedroom2)
client.on_message = mod.on_message
client.connect(broker, 1883, 60)
client.subscribe('/pi/#')

client.loop_start()
print('Script is running, press Ctrl-C to quit...')