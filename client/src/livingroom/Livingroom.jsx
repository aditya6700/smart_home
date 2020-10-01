import React from 'react';
import Controlcard from '../Controlcard';
import LivingData from './LivingData';


export default function Livingroom() {
    return (
        <>
        <section id="rooms">
        <div className="my-5 pt-5">
            <h1 className="text-center"> Controller of your Living Room
         </h1>
        </div>


          <div className="container-fluid mb-5">
             <div className="row">
                 <div className='col-10 mx-auto'>
                    <div className="row">
                      {
                        LivingData.map((value, index) => {
                            if(value.device !== null){
                              return <Controlcard
                                    key={index}
                                    device={value.device}
                                    status={value.status}
                                    type={value.type}
                                    readings={value.readings}
                                    room={value.room}
                              />
                            }else return null
                          })
                      }
                    </div>
                 </div>
             </div>
         </div>
         </section>
        </>
    )
}
