# SMART HOME AUTOMATION SYSTEM

     Your home in your hands. Control everything from one place. By the help of this project we can achieve    
> - Monitoring different sensors data.
> - Controlling different appliances.
> - Accessing past data.  

    This project comprises about the following stages  
> 1. Frontend UI using ReactJS.
> 2. Backend framework using NodeJS ane ExpressJS.
> 3. Database for storing data for future purpose.
> 4. NodeMCU for reading different sensors data and for accessing control for appliances.  
  
## How to start this project ?

**Prerequests**
 - Configuring NodeJS and ReactJS.
    - [click here](https://nodejs.org/en/) to install **node.js**
        - open `cmd` or `terminal`.
        - type `npm install -g nodemon` and click enter.
        - type `npm install -g create-react-app` and click enter.
 - Configuring NodeMCU
    - [click here](https://www.arduino.cc/en/software) to install Arduino IDE.
    - [click here](https://www.instructables.com/Steps-to-Setup-Arduino-IDE-for-NODEMCU-ESP8266-WiF/) for steps tp add NodeMCU compatibility for flasing NodeMCU.

**Stage 1**
> - navigate to _project_name\client_
> - open `cmd` or `terminal`
> - type `npm run start` and hit enter  
> **_you can see that ReactJS has started running on port 3000_**

**Stage 2**
> - navigate to _project_name\server_
> - open `cmd` or `terminal`
> - type `npm run devStart` and hit enter  
> **_you can see that NodeJS has started running on port 1432_**

**Stage 3**
> - open `terminal`
>   - type `sudo apt install mosquitto` and hit enter
>   - type `sudo apt install mosquitto-clients` and hit enter
>   - type `sudo apt install paho-mqtt` and hit enter
>   - type `python3 -m pip install yaml` and hit enter
>   - type `sudo apt install mariadb-server` and hit enter
>   - type `sudo mysql_secure_installation` and hit enter
> - navigate to _project_name\iot\python\
> - open python scripts and change *broker* ip address to raspberrypi ip address and save
>   - open `terminal`  type `ifconfig` and hit enter to know ip address
> - run python scripts

**Stage 4**
> - navigate to _project_name\iot\nodemcu_
> - open Arduino editor and change the following parameters in all the arduino files
>   - #define WLAN_SSID "WiFi_SSID"   
>   - #define WLAN_PASS "Password"   
>   - #define MQTT_SERVER "Raspi_ip_address"   
> - upload arduino files to each NodeMCU from each folder containing in this directory
>   - [click here]() for steps to upload code to NodeMCU