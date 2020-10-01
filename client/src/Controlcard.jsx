import React from 'react';
import Axios from 'axios'

export default function Common({device, status, type, readings, room }) {
 
    const handleOff = (room, device) => {
        console.log(room, device," OFF")
        Axios.post(`http://localhost:1432/api/esp8266/off`,{
            selectedRoom: room,
            selectedDevice: device,
        })
    }

    const handleOn = (room, device) => {
        console.log(room, device," ON")
        Axios.post(`http://localhost:1432/api/esp8266/on`,{
            selectedRoom: room,
            selectedDevice: device,
        })
    }
    return (
        <>
        <div className="col-md-4 col-10 mx-auto">
            <div className="card border-primary mb-4 "  >
            <div className="card-header"> {type === "Applaince" ? "Applaince" : "Sensor"} </div>
                <div className="card-body text-primary justify-content-center ">
                    <h5 className="card-title"> {device} </h5>
                    <p className="card-text">Your device status is 
                    <span style={{fontSize:"20px", color: status === "ON" ? "green" : "red" }}> {status} </span> </p>

                    {type === "Applaince" ? <>
                    <button type="button" 
                        id="on"
                        className="btn btn-outline-success"
                        onClick={() => handleOn(room,device) } >ON</button>
                    <button type="button" 
                        className="btn btn-outline-danger"
                        onClick={() => handleOff(room,device)} >OFF</button>
                     </> :
                      <>
                      <p className="card-text"> {device} in this room is {readings} </p>
                      <p></p>
                      </> }
                </div>
            </div>
        </div>
        </>
    );

}
