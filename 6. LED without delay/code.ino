long previousTime = 0;
long currentTime =0;
int interval = 1000;
bool ledState =0;
int count=0;
void setup(){
pinMode(13,OUTPUT);
  Serial.begin(9600);
}
void loop(){
 currentTime = millis();
  if(currentTime-previousTime>interval){
    ledState = !ledState;
    digitalWrite(13,ledState);
    previousTime=currentTime;
  }
  if(digitalRead(12)){
  Serial.println("Button Pressed!");
    count++;
    Serial.println(count);
    delay(150);
  }
}

