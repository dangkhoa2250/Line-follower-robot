
int sensorValue0=0;
int sensorValue1=0;
int sensorValue2 =0; 
 int n = 0;
void setup(){
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(3,INPUT_PULLUP);

  Serial.begin(9600);
  while(digitalRead(3)==HIGH){}
}

void loop(){
  checkLine();
  checkObstacle1();
}
  

void checkObstacle1(){
 if(sensorValue0 == HIGH  && sensorValue1 == HIGH && sensorValue2 == HIGH){
    n +=1;
      if (n % 2 == 0){
      Serial.println("avoid Right");
      turnRight(250);
      delay(500);
      forward(180);
      delay(1000);
      turnLeft(250);
      delay(1100);
      forward(150);
      }
      else{
      Serial.println("avoid Left");
      turnLeft(250);
      delay(500);
      forward(180);
      delay(1000);
      turnRight(250);
      delay(700);
      forward(150); 
      }
     Serial.println(n);
    
 }
}
  
void checkLine(){
 sensorValue0= digitalRead(A5);
 sensorValue1= digitalRead(A4);
 sensorValue2= digitalRead(12);
  
 if(sensorValue0 ==HIGH && sensorValue1 == LOW && sensorValue2 == HIGH)
 {
   Serial.println("turning right");
   turnRight(250); 
 }
  else if(sensorValue0 == LOW  && sensorValue1 == HIGH && sensorValue2 == HIGH)
 {
   Serial.println("turning left");
   
   turnLeft(250);
 }
 else if(sensorValue0 == LOW  && sensorValue1 == LOW && sensorValue2 == HIGH)
 {
   Serial.println("go forward");
   forward(160);
  }
 else if( sensorValue0 == LOW  && sensorValue1 == LOW && sensorValue2 == LOW)
 {
  backward(180);
 }
}
void forward(int speed) {
  analogWrite(5, 0);
  analogWrite(6, speed);
  analogWrite(10, speed);
  analogWrite(11, 0);
}

void turnLeft(int speed) {
  analogWrite(5, 0);
  analogWrite(6, speed);
  analogWrite(10, 0);
  analogWrite(11, 0);
}


void turnRight(int speed) {
  analogWrite(5, 0);
  analogWrite(6, 0);
  analogWrite(10, speed);
  analogWrite(11, 0);
}

void backward(int speed){
  analogWrite(5, speed);
  analogWrite(6, 0);
  analogWrite(10, 0);
  analogWrite(11, speed);
}

void stopMotor(){
 analogWrite(5, 0);
  analogWrite(6, 0);
  analogWrite(10, 0);
  analogWrite(11, 0);
}
