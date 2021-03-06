import React from 'react';
// import home from '../images/home.jpg';
import home1 from '../images/smarthome.jpg';
import hm1 from '../images/1 (5).jpeg';
import hm2 from '../images/1 (5).jpg'
import home from '../images/iot.png'

export default function Carousel() {
    return (
        <>
         <div id="carouselExampleIndicators" className="carousel slide" data-ride="carousel">
            <ol className="carousel-indicators">
                <li data-target="#carouselExampleIndicators" data-slide-to="0" className="active"></li>
                <li data-target="#carouselExampleIndicators" data-slide-to="1"></li>
                <li data-target="#carouselExampleIndicators" data-slide-to="2"></li>
                <li data-target="#carouselExampleIndicators" data-slide-to="3"></li>
            </ol>

            <div className="carousel-inner">
                <div className="carousel-item active">
                    <img className="w-100" src={hm1} alt="First slide"/>
                </div>
                <div className="carousel-item">
                    <img className="w-100" src={home1} alt="Second slide"/>
                </div>
                <div className="carousel-item">
                    <img className="w-100" src={hm2} alt="Third slide"/>
                </div>
                <div className="carousel-item">
                    <img className="w-100" src={home} alt="Fourth slide"/>
                </div>
            </div>

            <a className="carousel-control-prev" href="#carouselExampleIndicators" role="button" data-slide="prev">
                <span className="carousel-control-prev-icon" aria-hidden="true"></span>
                <span className="sr-only">Previous</span>
            </a>
            <a className="carousel-control-next" href="#carouselExampleIndicators" role="button" data-slide="next">
                <span className="carousel-control-next-icon" aria-hidden="true"></span>
                <span className="sr-only">Next</span>
            </a>
            <a className="carousel-control-next" href="#carouselExampleIndicators" role="button" data-slide="next">
                <span className="carousel-control-next-icon" aria-hidden="true"></span>
                <span className="sr-only">Next</span>
            </a>
        </div>  
        </>
    )
}
