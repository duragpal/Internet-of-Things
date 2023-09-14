// C++ code
//
void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop()
{
  float val =analogRead(A0);
  float mV=val*4.88;
  mV = mV-507.52;
  
  float tempC = mV/10;
  Serial.print(tempC);
  Serial.println(" C");
  delay(200);
}