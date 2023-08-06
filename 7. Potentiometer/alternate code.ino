int potentiometer = A0; 
 
void setup()
{
    Serial.begin(9600); 
    pinMode(potentiometer, INPUT);
}
 
void loop()
{   float rotation;
    int value = analogRead(potentiometer);
 	// Analog Read range : 0 - 1023
 //Angle range : 0 - 270
    //0(0) -512(135) - 1023(270)
  	   
  	//float rotation=map(value,0,1023,0,270);
    rotation = (float)value*0.2639;
    
    Serial.println("The angle between the mark and the starting position:");
    Serial.println(rotation);
}
