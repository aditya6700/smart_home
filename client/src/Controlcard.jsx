import React from 'react'


export default function Common({device, status, type, readings }) {
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
                    <button type="button" className="btn btn-outline-success">ON</button>
                    <button type="button" className="btn btn-outline-danger">OFF</button>
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
