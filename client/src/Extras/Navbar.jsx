import React from 'react';
import { NavLink } from 'react-router-dom';
 
 export default function Navbar() {
     return (
        <>
        <div className="container-fluid nav_bg">
            <div className="rows">
                <div className='col-12 mx-auto'>
                    <nav className="navbar navbar-expand-lg fixed-top  navbar-light bg-light">
                        <div className="container-fluid">
                            <NavLink exact  className="navbar-brand" to="/"> Smart Home </NavLink>
                            <button className="navbar-toggler" 
                                    type="button" 
                                    data-toggle="collapse" 
                                    data-target="#navbarSupportedContent"
                                    aria-controls="navbarSupportedContent" 
                                    aria-expanded="false" 
                                    aria-label="Toggle navigation">
                            <span className="navbar-toggler-icon"></span>
                            </button>

                            <div className="collapse navbar-collapse" id="navbarSupportedContent">
                            <ul className="navbar-nav ml-auto mb-2 mb-lg-0">
                                <li className="nav-item">
                                    <NavLink exact activeClassName="active_class" className="nav-link active" aria-current="page" to="/">Home</NavLink>
                                </li>
                                <li className="nav-item">
                                    <NavLink exact activeClassName="active_class" className="nav-link" to="/livingroom">Living Room</NavLink>
                                </li>
                                <li className="nav-item">
                                    <NavLink exact activeClassName="active_class" className="nav-link" to="/bedroom1">Bedroom 1</NavLink>
                                </li>
                                <li className="nav-item">
                                    <NavLink exact activeClassName="active_class" className="nav-link" to="/bedroom2">Bedroom 2</NavLink>
                                </li>
                                <li className="nav-item">
                                    <NavLink exact activeClassName="active_class" className="nav-link" to="/analytics">Analytics</NavLink>
                                </li>
                            </ul>
                            </div>
                        </div>
                    </nav>
                </div>
            </div>
        </div>
        </>
     );
 };
 