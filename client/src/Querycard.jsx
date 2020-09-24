import React from 'react'


export default function Querycard({
    hour,  
    light_1,   
    light_2,  
    Fan_1,  
    Fan_2,  
    Sensor_1, 
    Sensor_2 ,
    Sensor_3 ,
    Sensor_4}) 
    {
    return (
        <>
        <div className="col-md-4 p-0  col-10 mx-auto">
            <div className="card border-primary ml-2 mb-4 "  >
            <div className="card-header"> {hour.substr(11,8)} </div>
                <div className="card-body text-primary justify-content-center ">
                <table className="table">
                <tbody>
                    {(light_1 !== undefined) ? <tr><th scope="col">light_1 is on for {light_1}   </th></tr> : null }
                    {(light_2 !== undefined) ? <tr><th scope="col">light_2 is on for {light_2}   </th></tr> : null }

                    {(Fan_1 !== undefined) ? <tr><th scope="col">Fan_1 is on for {Fan_1}       </th></tr> : null }
                    {(Fan_2 !== undefined) ? <tr><th scope="col">Fan_2 is on for {Fan_2}       </th></tr> : null }

                    {(Sensor_1 !== undefined) ? <tr><th scope="col">Sensor_1 value is {Sensor_1}  </th></tr> : null }
                    {(Sensor_2 !== undefined) ? <tr><th scope="col">Sensor_2 value is {Sensor_2}  </th></tr> : null }
                    {(Sensor_3 !== undefined) ? <tr><th scope="col">Sensor_3 valuie is {Sensor_3} </th></tr> : null }
                    {(Sensor_4 !== undefined) ? <tr><th scope="col">Sensor_3 valuie is {Sensor_4} </th></tr> : null }
                    
                </tbody>
                </table>
                </div>
            </div>
        </div>
        </>
    );

}
