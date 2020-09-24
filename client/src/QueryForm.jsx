import React, {useState} from 'react';


const updateDate = () => {
    var date = new Date();
    var formattedDate = []
    // var minu = date.getMinutes()
    formattedDate.push(date.toISOString().substr(0, 10))
    for (let i = 1; i<=6; i++) {
        date.setDate(date.getDate() - 1);
        formattedDate.push( date.toISOString().substr(0, 10))
    }  
    return formattedDate;
};

export default function QueryForm({getData, Qroom, Qdate, loading}) {
    const [optionList, setoptionList] = useState(updateDate());

    return (
        <>
        <form className="form-group">
            <div className="row">
                <div className="form-group col-md-4">
                     <label htmlFor="inputRoom">Select Room</label>     
                    <select  className="form-control"  
                        id="inputRoom"
                         onChange={Qroom}
                         required > 
                        <option value="" >Choose Room...</option>
                        <option value="livingroom" >Living Room</option>
                        <option value="bedroom1" >Bedroom 1</option>
                        <option value="bedroom2" >Bedroom 2</option>
                    </select>  
                </div>
                <div className="form-group col-md-4">
                    <label htmlFor="inputDate">Date</label>
                    <select className="form-control" 
                        id="inputDate"
                        onClick={() => setoptionList(updateDate())}
                        onChange={Qdate}
                        required > 
                        <option value="" >Choose Date...</option>
                        {
                            optionList.map((val,index) => {
                                return <option key={index} value={val} > {val} </option>
                            })
                        }
                    </select>
                </div>
                    <div className="form-group col-md-2">
                    <br />
                    <button  
                        className="btn btn-outline-primary" 
                        onClick={getData}> Get Data 
                    </button>  
                    { loading ? <> <div className="spinner-border text-primary ml-1" role="status">
                            <span className="sr-only">Loading...</span> 
                            </div> </> : null }

                </div>
            </div>
        </form>   
     
        </>
    )
}
