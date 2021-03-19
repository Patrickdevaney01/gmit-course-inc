#define PIN_Anologue A0
#define PIN_Relay 13
#define PIN_LED1 12

//PID constants
double kp = 1;
double ki = 2;
double kd = 0;

double elapsedTime;
double error;
double lastError;
double setPoint;
double cumError, rateError;

// CLASS VARIABLES DECLARATION

//Passes data to the class constructor
Blinker blink1 = Blinker(PIN_LED1, 100, 100);
ReadSensor sensor1 = ReadSensor(PIN_Anologue, 100);
RelayControl Relay1(PIN_Relay,300);

void setup(){
      //sets the serial monitor to 9600 baud rate
        Serial.begin(9600);
        setPoint = 0; //set point at zero degrees
        
}   
 
void loop(){
      
        unsigned long CurrentTime = millis();
        bool ONorOFF;      

       //If the voltage drops below 2 we turn relay on or else relay stays off
        if(sensor1.getVoltage()< 2){
        ONorOFF = 1;
        }
        else
        ONorOFF = 0;

        //calls the functions contained in there classes
        sensor1.ReadSensorInput(CurrentTime);
        Relay1.setRelay(CurrentTime,ONorOFF);
        blink1.check(CurrentTime);

         //takes input from Sensor and sends it to the PID 
        double input = sensor1.getVoltage(); //read from Light Sensor connected to A0    
        double output = computePID(input,CurrentTime);
 
 Serial.print("X ,"); Serial.print(output); Serial.print(" ");
   Serial.println(" ");

}
 //PID control Function
double computePID(double inp,unsigned long currentTime){     
           unsigned long previousTime;  
           double out;    
        elapsedTime = (double)(currentTime -  previousTime);        //compute time elapsed from previous computation
        
         error =  setPoint - inp;                                // determine error
         cumError += error * elapsedTime;                // compute integral
         rateError = (error - lastError)/elapsedTime;   // compute derivative
 
         out = kp*error + ki*cumError + kd*rateError;                //PID output               
 
        lastError = error;                                //remember current error
        previousTime = currentTime;                        //remember current time
 
        return out;                                        //have function return the PID output
}
