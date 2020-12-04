int analogPin = A0;
int PushButton = 8;
int ledPin = 10;

void setup(){
  Serial.begin(9600);
  }

  void loop(){
    pinMode(ledPin, OUTPUT);
    pinMode(PushButton, INPUT); 
    
    int potread = analogRead(analogPin);
    float voltage = potread * (5.0/1023.0);
    
 if (digitalRead(PushButton) == HIGH)
    {
    digitalWrite(ledPin, HIGH); 
    Serial.println(voltage);
    }
 if (digitalRead(PushButton) == LOW)
    {
     digitalWrite(ledPin, LOW);
    }
 
 }
