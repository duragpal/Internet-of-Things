int potentiometer = A0; 
 
void setup()
{
    Serial.begin(9600); 
    pinMode(potentiometer, INPUT);
}
 
void loop()
{   float voltage;
    int value = analogRead(potentiometer);
 	
    //Serial.print("Potentiometer value: ");
  	   
  	delay(1000); 
    voltage = (float)value*5/1023;
    float degrees = (voltage*300)/5;
    Serial.println("The angle between the mark and the starting position:");
    Serial.println(degrees);
}
