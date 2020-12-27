import React, {useState} from 'react';
import QueryForm from './QueryForm'
import {history} from '../index';
import Querycard from './Querycard';
import Axios from 'axios';


export default function Query() {
    const [dataList, setDataList] = useState([])
    const [loading, setLoading] = useState(false)

    const [room, setRoom] = useState("");
    const [date, setDate] = useState("");
  
    
    const getData = (e) => {
        e.preventDefault();

        Axios.get( `http://localhost:1432/api/get/${room}/${date}`)
        .then((response) => {
            setLoading(false)
            setDataList(response.data);
        })
        .catch((error) => {  
            console.log(error.response);
            if(error.response.status === 404) history.push('/error')   
        })
        console.log(room,date);
    };

    return (
        <>
        <div className="my-5 pt-5">
            <h1 className="text-center"> Query your previous data here </h1>
        </div>  
         <div className="container fluid mb-5">
            <div className="row">  
                <div className="col-md-12  mx-auto">
                
                    <QueryForm
                        Qroom={(event) => setRoom(event.target.value)}
                        Qdate={(event) => setDate(event.target.value)}
                        getData={getData}
                        loading={loading}
                    /> <br />
               
                </div>
                <div className="row">
                     
                      {  
                        dataList.map((value, index) => {
                            
                               return <Querycard
                                        key={index}
                                        hour= {value.startTime}  
                                        light_1= {value.Light_1}  
                                        light_2= {value.Light_2} 
                                        Fan_1= {value.Fan_1} 
                                        AC= {value.Air_Conditioner} 
                                        Sensor_1= {value.Temperature} 
                                        Sensor_2= {value.Humidity} 
                                        Sensor_3= {value.Gas} 
                                        Sensor_4= {value.Smoke}
                                        endTime = {value.endTime}
                               />
                             } 
                           )
                       }   
                       
                 </div>
            </div> 
        </div> 
        </>
    )
}
