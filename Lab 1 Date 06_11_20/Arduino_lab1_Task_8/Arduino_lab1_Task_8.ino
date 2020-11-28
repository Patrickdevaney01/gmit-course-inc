int analogPin = A0;


void setup(){
  Serial.begin(9600);
  }

  void loop(){
    
    int potread = analogRead(analogPin);
    float voltage = potread * (5.0/1023.0);
    Serial.println(voltage);
 
 }
