#include <Servo.h>
int light1;
int light2;
int triggerpin = 12;
int echopin = 13;
long distance;
long sure;
int delayPot = A5;
int valilk =0;
int gecikme;
int buzzerPin = 8;
int ledPinJump = 6;
int ledPincrawl = 3;
int C = 262; //note for each jumping
int D = 293; // note for each crawling
int E = 329; //note for each using of ultrasonic sensor
Servo servospace;
Servo servocrouch;

void setup() {
  
  pinMode (triggerpin, OUTPUT);
  pinMode (echopin , INPUT);
  pinMode(ledPincrawl, OUTPUT);
  pinMode(ledPinJump, OUTPUT);
  servospace.attach(9);
  servocrouch.attach(10);
  Serial.begin(9600);
      
}


void loop() {
  light1 = analogRead(A1);
  light2 = analogRead(A2);
  
  digitalWrite(triggerpin , LOW);
  delayMicroseconds(5);
  digitalWrite(triggerpin , HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerpin , LOW);
  sure = pulseIn(echopin, HIGH);
  distance = sure /29.1/2;
    servospace.write(0);  
  servocrouch.write(0);
  
  int val = analogRead(A5);
  val= map(val,0,1023,1,5);
  if(val!= valilk){
    if (val==1){
      gecikme = 80;}
    else if (val==2){
      gecikme = 75;}
    else if (val==3){
      gecikme = 60;}
    else if (val ==4){
      gecikme= 45;}
  else if (val== 5){
      gecikme = 30;}
  }
 
  //Serial.print ("LDR_1: "); Serial.print(light1);
  //Serial.print ("  -_-_-_-  ");
  //Serial.print ("LDR_2: ");Serial.println(light2);
  Serial.print("jumping delay: ");
  Serial.println(gecikme);
   
  
  if(light1<60) {
    servospace.write(70);
    digitalWrite(ledPinJump, HIGH);    
    tone(buzzerPin,C);
    delay(gecikme);
    noTone(buzzerPin); 
    digitalWrite(ledPinJump, LOW);
     }
    else {
      servospace.write(0);
      }
      
      if(light2>600) {
    servocrouch.write(70);
    digitalWrite(ledPincrawl, HIGH);
    tone(buzzerPin,D);     
    delay(gecikme);
    noTone(buzzerPin);
    digitalWrite(ledPincrawl, LOW);
    }
     else{
      servocrouch.write(0);
      }


  
     if (distance <30 )
     {
        servospace.write(70);
        tone(buzzerPin,E);
        digitalWrite(ledPincrawl, HIGH);
        delay(80);
        servospace.write(0);
        noTone(buzzerPin); 
        digitalWrite(ledPincrawl, LOW); 
            }
    else{
      servospace.write(0);
      }
}
