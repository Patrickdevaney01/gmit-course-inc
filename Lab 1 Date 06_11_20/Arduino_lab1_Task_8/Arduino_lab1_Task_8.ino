const int analogPin = A1;
const int ledPin = 4;

void setup(){
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  }

  void loop(){
    int potread = analogRead(analogPin);
    float voltage = potread * (5.0/1023.0);
    Serial.println(voltage);
    
  }
