/*
This P5 sketch is a template for getting started with Serial Communication. 
The SerialEvent callback is where incoming data is received 

By Arielle Hein, adapted from ITP Phys Comp Serial Labs
Edited March 12 2019
*/

var serial; //variable to hold an instance of the serial port library
var portName = 'COM3'; //fill in with YOUR port

var input_x = 0;
var input_y = 0;
var button = 0;

function setup() {
  createCanvas(400, 400);

  serial = new p5.SerialPort(); //a new instance of serial port library

  //set up events for serial communication
  serial.on('connected', serverConnected);
  serial.on('open', portOpen);
  serial.on('data', serialEvent);
  serial.on('error', serialError);
  serial.on('close', portClose);

  //open our serial port
  serial.open(portName);

  //let's figure out what port we're on - useful for determining your port
  // serial.on('list', printList); //set a callback function for the serialport list event
  // serial.list(); //list the serial ports
}

function draw() {
  background('gray');
  if(button === 0){
    background('yellow');
  }
  fill(color('blue'));
  rect(input_x, input_y, 50, 50);
  
}


//all my callback functions are down here:
//these are useful for giving feedback

function serverConnected(){
  console.log('connected to the server');
}

function portOpen(){
  console.log('the serial port opened!');
}

//THIS IS WHERE WE RECEIVE DATA!!!!!!
//make sure you're reading data based on how you're sending from arduino
function serialEvent(){
	//receive serial data here
  var data = serial.readLine();
  if(data === "")return;
  var split = data.split(',');
  ///console.log(split[0],split[1],split[2]);
  button = map(split[0], 0, 1010, 0, 1);
  input_x = map(split[1], 0,1023,0,350);
  input_y = map(split[2], 0,1023,0,350);
  console.log(button, input_x, input_y);
}

function serialError(err){
  console.log('something went wrong with the port. ' + err);
}

function portClose(){
  console.log('the port was closed');
}

// get the list of ports:
function printList(portList) {
 // portList is an array of serial port names
 for (var i = 0; i < portList.length; i++) {
 // Display the list the console:
 print(i + " " + portList[i]);
 }
}