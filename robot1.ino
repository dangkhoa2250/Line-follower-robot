int sensorValue0=0;
int sensorValue1=0;
int sensorValue2=0;
void setup(){
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(3,INPUT_PULLUP);

  Serial.begin(9600);
  while(digitalRead(3)==HIGH){}
}
void loop(){
sensorValue0= digitalRead(A5);
sensorValue1= digitalRead(A4);
sensorValue2= analogRead(A3);
 Serial.println(sensorValue2);
 
 if(sensorValue2 >50 ){
  Serial.println("go straight");
  delay(2000);
 }
 else{
  Serial.println("avoid");
  delay(2000);
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

void forward() {
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void turnLeft() {
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

void turnRight() {
  digitalWrite(5,LOW);
  digitalWrite(6, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void backward(){
  digitalWrite(5,HIGH);
  digitalWrite(6, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}

void stopMotor(){
  digitalWrite(5,LOW);
  digitalWrite(6, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
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
