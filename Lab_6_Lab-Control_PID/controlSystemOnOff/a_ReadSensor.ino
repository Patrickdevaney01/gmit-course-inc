//Pin defination


// READ SENSOR CLASS DEFINITION

class ReadSensor{

//Defining class variables
  private:
  int Pin_Input;
  int Sample_Time;
  float sensorValue;
  int voltage;
  unsigned long nextChangeTime = 0;
  
  public:
//constructor taking inputs from main tab and applying them to class variables

   ReadSensor(byte Pin_Input,int Sample_Time){
    this->Pin_Input = Pin_Input;
    this->Sample_Time = Sample_Time;
   }

//Function for reading an anologue input

   void ReadSensorInput(unsigned long currentTime){  
    
    
//data output smoothing
    if(currentTime >= nextChangeTime) {
      
//reads from anologue pin a0 and converts to a voltage
     this->sensorValue = analogRead(Pin_Input);
     this->voltage = sensorValue * (5.0 / 1023.0);
      nextChangeTime = currentTime + Sample_Time;
    }
   }
   
// Function to return the Sensor input to the main tab so it can be printed
   float getsensorValue(){
      return sensorValue;
    }
 // Function to return the Voltage to the main tab so it can be printed
    int getVoltage(){
      return voltage;
    }
 };
