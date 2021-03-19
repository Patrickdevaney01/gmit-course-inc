


class RelayControl{
private:

  byte PIN_Relay;

  boolean ledState = LOW;

  unsigned long timeinterval;
  unsigned long nextchangetime = 0;

  public:

    RelayControl(byte pin, unsigned long Time){
      
      this -> PIN_Relay = pin;
      this -> timeinterval = Time;
      pinMode(PIN_Relay,OUTPUT);
  
    }

    void setRelay(unsigned long currentTime,bool ONOFFSet){
      if(currentTime>= nextchangetime){
        digitalWrite(PIN_Relay,ONOFFSet);
          nextchangetime = currentTime + timeinterval;
      }
    }
  
};
 
