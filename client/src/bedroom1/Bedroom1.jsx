import React from 'react';
import Controlcard from '../Controlcard';
import Bedroom1Data from './Bedroom1Data';

export default function Bedroom1() {
    return (
        <>
            <section id="rooms">
        <div className="my-5 pt-5">
            <h1 className="text-center"> Controller of your Bedroom 1 </h1>
        </div>
          <div className="container-fluid mb-5">
             <div className="row">
                 <div className='col-10 mx-auto'>
                    <div className="row">
                      {
                        Bedroom1Data.map((value, index) => {
                            if( value.device !== null){
                              return <Controlcard
                                    key={index}
                                    device={value.device}
                                    status={value.status}
                                    type={value.type}
                                    readings={value.readings}
                              />
                            } else return null
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
