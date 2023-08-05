int trig=7;
int echo=8;
long duration=0;
float distance=0;
void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2); 
  digitalWrite(trig, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);
  
  duration=pulseIn(echo, HIGH);
  distance=duration*0.034/2;
  Serial.println("Distance = "+ String(distance)+ "Cm");
}