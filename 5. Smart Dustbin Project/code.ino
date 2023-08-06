#include<Servo.h>
#define servoMot 3
#define u1_trig 4
#define u1_echo 5
#define u2_trig 6
#define u2_echo 7
#define buzzer 9
#define greenled 10
#define redled 11

int dist1 = 0;
int dist2 = 0;
long duration=0;
bool dustEmpty = true;
bool alertFlag;

Servo myServo;


int distance(int trig, int echo){
  digitalWrite(trig, LOW);
  delayMicroseconds(2); 
  digitalWrite(trig, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);
  duration=pulseIn(echo, HIGH);
  return duration*0.0175;
}

void setup(){
  Serial.begin(9600);
  myServo.attach(servoMot);
  pinMode(u1_trig, OUTPUT);
  pinMode(u1_echo, INPUT);
  pinMode(u2_trig, OUTPUT);
  pinMode(u2_echo, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  myServo.write(0);
  delay(20);
  
}
void loop()
{
  dist1 = distance(u1_trig,u1_echo);
  dist2 = distance(u2_trig,u2_echo);
  if(dist1>=10)
  {
    digitalWrite(greenled,HIGH);
    digitalWrite(redled,LOW);
    dustEmpty=true;
    alertFlag=true;
    
  }
  else if(dist1<10)
  {
    digitalWrite(greenled,LOW);
    digitalWrite(redled,HIGH);
    duwstEmpty=false;
    if (alertFlag==true)
    {
      tone(buzzer,1000,20);
      delay(1000);
      tone(buzzer,1000,20);
      delay(1000);
      tone(buzzer,1000,20);
    }
  }
  if (dist2<=25 && dustEmpty==true)
  {
    myServo.write(90);
    delay(50);
  
  }
  else if(dist2>25){
    myServo.write(0);
    delay(20);
  
  }
		  
}