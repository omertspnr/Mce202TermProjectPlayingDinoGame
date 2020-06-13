
#include <Servo.h>
int light1;
int light2;
int triggerpin = 12;
int echopin = 13;
long distance;
long sure;
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
  Serial.begin(9600);
  servospace.attach(9);
  servocrouch.attach(10);

}

void loop() {
  digitalWrite(triggerpin , LOW);
  delayMicroseconds(5);
  digitalWrite(triggerpin , HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerpin , LOW);
  sure = pulseIn(echopin, HIGH);
  distance = sure /29.1/2;
  servospace.write(0);  
  servocrouch.write(0);
  light1 = analogRead(A1);
  light2 = analogRead(A0);
  Serial.print ("LDR_1: "); Serial.print(light1);
  Serial.print ("  -_-_-_-  ");
  Serial.print ("LDR_2: ");Serial.println(light2);
  delay(40);

  
  if(light1<60) {
    servospace.write(70);
    digitalWrite(ledPinJump, HIGH);    
    tone(buzzerPin,C);
    delay(80);
    noTone(buzzerPin); 
    digitalWrite(ledPinJump, LOW);
     }
    else {
      servospace.write(0);
      }
      
      if(light2<130) {
    servocrouch.write(70);
    digitalWrite(ledPincrawl, HIGH);
    tone(buzzerPin,D);     
    delay(80);
    noTone(buzzerPin);
    digitalWrite(ledPincrawl, LOW);
    }
    else {
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
