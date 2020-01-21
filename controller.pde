import processing.serial.*; //impors serial library to use bluetooth

PImage backGround; //background image variable

//variables for starting positions of direction line and power rectangle
float rectX = 105;
float rectY = 765;
float lineX = 961;
float lineY = 200;
int powerCount = 0;  //varialbe used to limit power levle
int directionCount = 0; //varialbe used to limit direction degrees
//Serial port;

void setup(){
  //port = new Serial(this, Serial.list()[2], 9600); //creates new serial port
  fullScreen(); //makes the program fullscreen
  backGround = loadImage("bg.jpg"); //sets background
  
}

//draw funtion to continoulsy loop
void draw(){
  background(backGround); //redraws background to avoid duplicate images
  
  //calls update functions to redraw direction line and power indicator rectangle
  updatePower(rectX, rectY);
  updateDirection(lineX, lineY);
}

//function that updates power rectangle
void updatePower(float x, float y){
  fill(0);
  rect(x,y,130.5,25);
  //stops rectangle from going over allowed limit
  if(rectY <= 391){
    rectY = 765;
    powerCount = 0;
  }
}

//funtion that updates direction line
void updateDirection(float x, float y){
  stroke(255,255,255);
  strokeWeight(7);
  line(961, 439, x, y);
}


void keyPressed(){ //key press is called when any key is pressed
  if(key == CODED){ //checks to see if key is a special key (arrows, shift key, control key ect.)
    if(keyCode == UP){
      switch(powerCount){ //writes serial data depending on current power level to control speed of the car
        /*case 1: port.write(65); break;
        case 2: port.write(66); break;
        case 3: port.write(67); break;
        case 4: port.write(68); break;
        case 5: port.write(69); break;
        default:port.write(0); break;*/
      }
    }
    if(keyCode ==DOWN){
      switch(powerCount){
        /*case 1: port.write(72); break;
        case 2: port.write(73); break;
        case 3: port.write(74); break;
        case 4: port.write(75); break;
        case 5: port.write(76); break;
        default:port.write(0); break;*/
      }
    }
  }
  else{ //if key is not special key code is jumped to here
  
  //changes power level from 1-5 depeing on which number is pressed
  if(key == '1'){
       rectY = 765;
       powerCount = 1;
  }   
  else if(key == '2'){
      rectY = 685;
      powerCount = 2;
  }
  
  else if(key == '3'){
      rectY = 595;
      powerCount = 3;
  }
  
  else if(key == '4'){
      rectY = 505;
      powerCount = 4;
  }
  else if(key == '5'){
      rectY = 425;
      powerCount = 5 ;
  }
  
  //key to turn left
  else if(key == 'a'){
    if(directionCount>=-4){
       //port.write(70); //writes serial data to turn left
       lineX -= 50; //updates direction line variable
       directionCount -=1;
    }
  }
  
  //key to turn right
  else if(key =='d'){
    if(directionCount<=4){
      //port.write(71);
      lineX +=50;
      directionCount += 1;
    }
  }
 }
}
