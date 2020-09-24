import React from 'react';
import Carousel from './Carousel';
import Modal from './Modal';
// import { NavLink } from 'react-router-dom';



export default function Home() {
    return (
        <>
        <section id="header" className="d-flex align-items-center">
           <div className="container-fluid ml-2">
                <div className="row">
                    <div className='col-12 mx-auto'>
                        <div className="row">
                            <div className="col-md-5 pt-5 pt-lg-0 order-2 order-lg-1 d-flex justify-content-center flex-column">
                                <h1> Welcome to your<br /> 
                                <strong className="brand-name"> Smart Home Controller </strong></h1>
                                <h4 className="my-3">Your home in your hands. Control everything from here </h4>
                                <Modal />                      
                            </div>
                            <div className="home_carousel col-7 order-1 order-lg-2 ">
                                 <Carousel />
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </section>
        </>
    )
}
