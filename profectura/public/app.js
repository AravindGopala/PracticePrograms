// Import the functions you need from the SDKs you need


// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
// For Firebase JS SDK v7.20.0 and later, measurementId is optional
const firebaseConfig = {
    apiKey: "AIzaSyCKN8POycpMLRrfHEvsV1uPS-sZeVfA7mg",
    authDomain: "profectura.firebaseapp.com",
    databaseURL: "https://profectura-default-rtdb.firebaseio.com",
    projectId: "profectura",
    storageBucket: "profectura.appspot.com",
    messagingSenderId: "1014200375176",
    appId: "1:1014200375176:web:7e8586e5b24391decc0c3d",
    measurementId: "G-MSEZHQV1ZF"
};

// Initialize Firebase
firebase.initializeApp(firebaseConfig)

// Reference contact Info collections
let contactInfo = firebase.database().ref("infos");

document.querySelector(".contact_form").addEventListener("submit", submitForm)

function submitForm(e) {
    e.preventDefault();

    // Get input values
    let name = document.getElementById("name").value;
    let email = document.getElementById("email").value;
    let message = document.getElementById("msg").value;
    console.log(name, email, message)

    saveContactInfo(name, email, message)
    document.getElementById("contact_form").reset()
}

function saveContactInfo(name, email, message) {
    let newContactInfo = contactInfo.push();

    newContactInfo.set({
        name: name,
        email: email,
        message: message,
    });
}