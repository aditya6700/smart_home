import React from 'react';
import { Route, Switch } from 'react-router-dom';
import '../node_modules/bootstrap/dist/css/bootstrap.min.css';
import '../node_modules/bootstrap/dist/js/bootstrap.bundle.js'
import Home from './HomePage/Home';
import Livingroom from './Rooms/livingroom/Livingroom';
import Bedroom1 from './Rooms/bedroom1/Bedroom1';
import Bedroom2 from './Rooms/bedroom2/Bedroom2';
import Navbar from './Extras/Navbar';
import Query from './QueryPage/Query';
import Error from './Extras/Error';
// import Footer from './Extras/Footer';


function App() {
  return (
    <>
    <Navbar />
      <Switch>
        <Route exact path='/' component={Home} />
        <Route exact path='/livingroom' component={Livingroom} />
        <Route exact path='/bedroom1' component={Bedroom1} />
        <Route exact path='/bedroom2' component={Bedroom2} />
        <Route exact path='/analytics' component={Query} />
        <Route exact path='/error' component={Error} />
        <Route component={Error} />
      </Switch>
      {/* <Footer /> */}
    </>
  );
}

export default App;
