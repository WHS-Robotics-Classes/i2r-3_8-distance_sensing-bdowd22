int trigPin = 11;   
int echoPin = 12;    
long duration, cm, inches;
 
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}
 
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  cm = (duration/2) / 29.1;     
  inches = (duration/2) / 74;  
  
  if(cm<=10){
    analogWrite(6,0);
    analogWrite(5,0);
    analogWrite(3,255);
  }
  else if(cm>=11 && cm<=20){
    analogWrite(6,0);
    analogWrite(5,255);
    analogWrite(3,255);
  }
  else{
    analogWrite(6,0);
    analogWrite(5,128);
    analogWrite(3,0);
  }
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(250);
}
