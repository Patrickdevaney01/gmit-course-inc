#define PinA 8
#define PinB 9
#define PinC 10
#define PinD 11
#define SpeedInputPin A0
#define ForwardButton 2
#define ReverseButton 3
#define NUMBER_OF_STEPS_PER_REV 512

int MotorSpeed = 0;
int ForwardButtonState = 0;
int ReverseButtonState = 0;
aStepper motorStep = aStepper(PinA ,PinB ,PinC ,PinD);


void setup() {
      pinMode(ForwardButton,INPUT); 
      pinMode(ReverseButton,INPUT);
}

void loop() {
  
      //Read the state of the pushbutton
      ForwardButtonState = digitalRead(ForwardButton);
      ReverseButtonState = digitalRead(ReverseButton);
      
      //If the pushbutton is pressed ButtonState goes High
      if(ForwardButtonState == HIGH){
        
       //Runs the Motor Forward for 1 Revolution
      for(int i = 0;i < NUMBER_OF_STEPS_PER_REV; ++i){
            MotorSpeed = analogRead(SpeedInputPin);
            float Speed = MotorSpeed * (5.0/1023);
            motorStep.StepForward(Speed); 
        }
      }
      
      //If the pushbutton is not pressed ButtonState goes Low
      if(ReverseButtonState == HIGH){
        
      //Runs the Motor in Reverse for 1 Revolution
      for(int i = 0;i < NUMBER_OF_STEPS_PER_REV; ++i){
            MotorSpeed = analogRead(SpeedInputPin);
            float Speed = MotorSpeed * (5.0/1023);
            motorStep.StepReverse(Speed);    
        }
      }
}
