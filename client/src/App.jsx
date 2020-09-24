import React from 'react';
import { Route, Switch } from 'react-router-dom';
import '../node_modules/bootstrap/dist/css/bootstrap.min.css';
import '../node_modules/bootstrap/dist/js/bootstrap.bundle.js'
import Home from './Home';
import Livingroom from './livingroom/Livingroom';
import Bedroom1 from './bedroom1/Bedroom1';
import Bedroom2 from './bedroom2/Bedroom2';
// import Footer from './Footer';
import Navbar from './Navbar';
import Query from './Query';
import Error from './Error';


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
