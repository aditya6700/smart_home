import React from 'react'

export default function Footer() {
    const year =  new Date().getFullYear();
    return (
        <>
            <footer className="text-xs-center footerA bg-inverse text-white">
                <p> ©{year} reserved by The Sudo Club </p>
            </footer>
        </>
    )
}
