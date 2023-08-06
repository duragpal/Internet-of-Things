// C++ code
//
int count=0;
void setup()
{
  Serial.begin(9600);
  pinMode(12,INPUT);
  pinMode(13,INPUT);
}

void loop()
{
  int value1 = digitalRead(12);
  int value2 = digitalRead(13);
  
  Serial.println(count);
  delay(200);
  if (value1==1){
  count+=1;}
  else if (value2==1){
  count-=1;}
  
}