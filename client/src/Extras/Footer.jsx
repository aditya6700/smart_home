import React from 'react'

export default function Footer() {
    const year =  new Date().getFullYear();
    return (
        <>
            <footer className="text-xs-center footerA bg-inverse text-black">
                <p> ©{year} reserved by The Sudo Club </p>
            </footer>
        </>
    )
}
