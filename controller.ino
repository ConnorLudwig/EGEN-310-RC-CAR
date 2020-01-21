#include <Servo.h> //servo library
//servo variables
Servo frontServo; 
Servo backServo;

//servo starting positions
int frontPos = 85;
int backPos = 86;
//value to hold bluetooth inputs
char val;
//pin variables
int logicPin = 2;
int BIN_1 = 10;
int BIN_2 = 11;
int AIN_1 = 5;
int AIN_2 = 6;



//setup function
void setup() {
  //setup servo pins
  frontServo.attach(3);
  backServo.attach(9);
  
  //start servos in center position
  frontServo.write(frontPos);
  backServo.write(backPos);
  
  //set pin mode
  pinMode(BIN_1, OUTPUT);
  pinMode(BIN_2, OUTPUT);
  pinMode(AIN_1, OUTPUT);
  pinMode(AIN_2, OUTPUT);
  Serial.begin(9600);
}
//loop funtion to be repeated
void loop() {
  if( Serial.available() ) //checks to see if serial data is avaible
  {
    val = Serial.read(); //sets val to serial data

//-------------------------------Stets PWM vlaue (speed of DC Motors) depending on which data is in val-------------------------------
    if(val == 'A'){
    digitalWrite(logicPin, HIGH); //logic pin is required to activate h-bridge
    digitalWrite(BIN_2, LOW); 
    digitalWrite(AIN_2, LOW);
    analogWrite(BIN_1, 215);
    analogWrite(AIN_1, 215);
    }
    else if(val == 'B'){
    digitalWrite(logicPin, HIGH);
    digitalWrite(BIN_2, LOW);
    digitalWrite(AIN_2, LOW);
    analogWrite(BIN_1, 225);
    analogWrite(AIN_1, 225);
    }
    else if(val == 'C'){
    digitalWrite(logicPin, HIGH);
    digitalWrite(BIN_2, LOW);
    digitalWrite(AIN_2, LOW);
    analogWrite(BIN_1, 235);
    analogWrite(AIN_1, 235);
    }
    else if(val == 'D'){
    digitalWrite(logicPin, HIGH);
    digitalWrite(BIN_2, LOW);
    digitalWrite(AIN_2, LOW);
    analogWrite(BIN_1, 245);
    analogWrite(AIN_1, 245);
    }
    else if(val == 'E'){
    digitalWrite(logicPin, HIGH);
    digitalWrite(BIN_2, LOW);
    digitalWrite(AIN_2, LOW);
    analogWrite(BIN_1, 255);
    analogWrite(AIN_1, 255);
    }
    else if(val == 'H'){
    digitalWrite(logicPin, HIGH);
    digitalWrite(BIN_1, LOW);
    digitalWrite(AIN_1, LOW);
    analogWrite(BIN_2, 215);
    analogWrite(AIN_2, 215);
    }
    else if(val == 'I'){
    digitalWrite(logicPin, HIGH);
    digitalWrite(BIN_1, LOW);
    digitalWrite(AIN_1, LOW);
    analogWrite(BIN_2, 225);
    analogWrite(AIN_2, 225);
    }
    else if(val == 'J'){
    digitalWrite(logicPin, HIGH);
    digitalWrite(BIN_1, LOW);
    digitalWrite(AIN_1, LOW);
    analogWrite(BIN_2, 235);
    analogWrite(AIN_2, 235);
    }
    else if(val == 'K'){
    digitalWrite(logicPin, HIGH);
    digitalWrite(BIN_1, LOW);
    digitalWrite(AIN_1, LOW);
    analogWrite(BIN_2, 245);
    analogWrite(AIN_2, 245);
    }
    else if(val == 'L'){
    digitalWrite(logicPin, HIGH);
    digitalWrite(BIN_1, LOW);
    digitalWrite(AIN_1, LOW);
    analogWrite(BIN_2, 255);
    analogWrite(AIN_2, 255);
    }

    //moves servo 6 degrees to the left
    else if(val == 'F'){
      for(int i = 1; i<=6; i++){
        frontServo.write(frontPos - i);
      }
      frontPos = frontPos - 6;
    }

    //moves servo 6 degrees to the left
    else if(val == 'G'){
      for(int i = 1; i<=6; i++){
 
        frontServo.write(frontPos + i);
      }
      frontPos = frontPos + 6;
    }
    
   }
   else{
    //sets all inputs to 0 if no serial data is aviable so the car doesn't continue to preform movements when no promted to
    analogWrite(AIN_1,0);
    analogWrite(AIN_2,0);
    analogWrite(BIN_1,0);
    analogWrite(BIN_2,0);
    
    
  }
    //delay to avoid buffer overflows
    delay(100);


    
 }
