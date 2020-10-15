import React from 'react'


export default function Querycard({
    hour,  
    light_1,   
    light_2,  
    Fan_1,  
    AC,  
    Sensor_1, 
    Sensor_2 ,
    Sensor_3 ,
    Sensor_4,
    endTime}) 
    {
    return (
        <>
        <div className="col-md-4 p-0  col-10 mx-auto">
            <div className="card border-primary ml-2 mb-4 "  >
            <div className="card-header"> {hour.substr(11,8)} to {endTime} </div>
                <div className="card-body text-primary justify-content-center ">
                <table className="table">
                <tbody>
                    {(light_1 !== undefined) ? <tr><th scope="col">light_1 is on for {light_1} minutes</th></tr> : null }
                    {(light_2 !== undefined) ? <tr><th scope="col">light_2 is on for {light_2} minutes</th></tr> : null }

                    {(Fan_1 !== undefined) ? <tr><th scope="col">Fan_1 is on for {Fan_1} minutes</th></tr> : null }
                    {(AC !== undefined) ? <tr><th scope="col">AC is on for {AC} minutes</th></tr> : null }

                    {(Sensor_1 !== undefined) ? <tr><th scope="col">Temperature is {Sensor_1}  Celcius</th></tr> : null }
                    {(Sensor_2 !== undefined) ? <tr><th scope="col">Humidity level is {Sensor_2} % </th></tr> : null }
                    {(Sensor_3 !== undefined) ? <tr><th scope="col">Gas level is {Sensor_3} </th></tr> : null }
                    {(Sensor_4 !== undefined) ? <tr><th scope="col">Smoke  {Sensor_4}'O </th></tr> : null }
                    
                </tbody>
                </table>
                </div>
            </div>
        </div>
        </>
    );

}
