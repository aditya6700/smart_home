import React from 'react'

export default function Modal() {
    return (
        <>
        <button type="button" 
            className="btn btn-outline-primary col-3" 
            data-toggle="modal" 
            data-target="#myModal">
            Know more
        </button>

        {/* <!-- The Modal --> */}
        <div className="modal" id="myModal">
            <div className="modal-dialog modal-dialog-scrollable">
                <div className="modal-content">
            
                {/* <!-- Modal Header --> */}
                <div className="modal-header">
                    <h1 className="modal-title">Overview</h1>
                    <button type="button" className="close" data-dismiss="modal">×</button>
                </div>
                
                {/* <!-- Modal body --> */}
                <div className="modal-body">
                    <h3>Instructions</h3>
                    <p>Some text to enable scrolling.. Lorem ipsum dolor sit amet, 
                        consectetur adipiscing elit, sed do eiusmod tempor incididunt 
                        ut labore et dolore magna aliqua. Ut enim ad minim veniam, 
                        quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea 
                        commodo consequat. Duis aute irure dolor in reprehenderit in 
                        voluptate velit esse cillum dolore eu fugiat nulla pariatur. 
                        Excepteur sint occaecat cupidatat non proident, sunt in culpa qui 
                        officia deserunt mollit anim id est laborum consectetur adipiscing elit, sed do eiusmod 
                        tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud
                        exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.
                    </p>
                </div>
                
                {/* <!-- Modal footer --> */}
                <div className="modal-footer">
                    <button type="button" className="btn btn-danger" data-dismiss="modal">Close</button>
                </div>
                </div>
            </div>
        </div>  
        </>
    )
}
