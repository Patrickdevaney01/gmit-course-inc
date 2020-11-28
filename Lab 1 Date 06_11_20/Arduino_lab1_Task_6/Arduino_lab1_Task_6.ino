int led = 9;
int led2 = 7;
int led3 = 4;
int brightness = 0;
int fadeamount = 5;



void setup() {
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

}

void loop() {
  analogWrite(led, brightness);
  
  brightness = brightness + fadeamount;
  
  if(brightness == 0 || brightness == 255) {
    fadeamount = -fadeamount; 
    delay(300);
  }
  
  digitalWrite (led2, HIGH);
  delay (1000);
  digitalWrite (led2, LOW);
  delay (1000);

  digitalWrite (led3, HIGH);
  delay (500);
  digitalWrite (led3, LOW);
  delay (500);
  

}
