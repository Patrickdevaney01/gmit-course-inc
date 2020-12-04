
const int PushButton = 8;
const int ledPin = 10;

int LedState = LOW;
int ButtonState;
int LastButtonState = LOW;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup(){
  
    pinMode(ledPin, OUTPUT);
    pinMode(PushButton, INPUT); 
    digitalWrite(ledPin, LedState);
  }

  void loop(){

    int reading = digitalRead(PushButton);

    if (reading != LastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
    
  }

    if ((millis() - lastDebounceTime) > debounceDelay) {
      
      if (reading != ButtonState) {
      ButtonState = reading;
      
      
       if (ButtonState == HIGH) {
        LedState = !LedState;
        
          }
       }
    }
    
    digitalWrite(ledPin, LedState);
    LastButtonState = reading;
  }
