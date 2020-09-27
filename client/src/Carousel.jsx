import React from 'react';
import home from './images/home.jpg';
import home1 from './images/smarthome.jpg';
import home2 from './images/Untitled.png';

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
                    <img className="d-block w-100" src={home2} alt="First slide"/>
                </div>
                <div className="carousel-item">
                    <img className="d-block w-100" src={home1} alt="Second slide"/>
                </div>
                <div className="carousel-item">
                    <img className="d-block w-100" src={home1} alt="Third slide"/>
                </div>
                <div className="carousel-item">
                    <img className="d-block w-100" src={home} alt="Fourth slide"/>
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


        
 
  {/* <section className="text_part">
    <div className="text">
     <h2 >your text</h2>
   </div>
 </section>

 <div id="carouselExampleIndicators" className="carousel slide" data-ride="carousel">
  <ol className="carousel-indicators">
    <li data-target="#carouselExampleIndicators" data-slide-to="0" className="active"></li>
    <li data-target="#carouselExampleIndicators" data-slide-to="1"></li>
    <li data-target="#carouselExampleIndicators" data-slide-to="2"></li>
  </ol>
  <div className="carousel-inner" role="listbox">
 
     <div className="carousel-item active" style={{backgroundColor: "gray"}}>
      <div className="carousel-caption  d-md-block">
        <div className="row">
          <div className="col-md-6 left_part">
            your text
          </div>
          <div className="col-md-6 col-sm-12">
           img
          </div>
        </div>
      </div>
    </div>
 
     <div className="carousel-item" style={{backgroundColor: "pink"}}>
      <div className="carousel-caption  d-md-block">
        <div className="row">
          <div className="col-md-6 left_part">
            your text
          </div>
          <div className="col-md-6 col-sm-12">
           img
          </div>
        </div>
      </div>
    </div>
 
     <div className="carousel-item" style={{backgroundColor: "green"}}>
     <div className="carousel-caption  d-md-block">
        <div className="row">
          <div className="col-md-6 left_part">
            your text
          </div>
          <div className="col-md-6 col-sm-12">
           img
          </div>
        </div>
      </div>
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
</div>  */}

 
        </>
    )
}
