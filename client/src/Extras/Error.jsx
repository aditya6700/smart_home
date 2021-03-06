import React from 'react'
import { NavLink } from 'react-router-dom'
import errorimg from '../images/errorimg.png';

export default function Error() {
    return (

 <section id="error" className="d-flex align-items-center">
           <div className="container-fluid">
                <div className="row">
                    <div className='col-10 mx-auto'>
                        <div className="row">
                            <div className="col-md-6 pt-5 pt-lg-0 order-2 order-lg-1 d-flex justify-content-center flex-column">
                                <h1> Error! 404 page not found </h1>
                                <div className="mt-3">
                                    <NavLink to="/" className="btn-get-started"> Go Back </NavLink>
                                </div>
                            </div>
                            <div className="col-lg-6 order-1 order-lg-2 header-img">
                                <img src={errorimg} className="img-fluid animated" alt="errorimg" />
                            </div> 
                        </div>
                    </div>
                </div>
            </div>
        </section>
    )
}
