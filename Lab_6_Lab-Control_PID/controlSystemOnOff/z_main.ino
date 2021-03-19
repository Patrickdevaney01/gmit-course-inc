#define PIN_Anologue A0
#define PIN_Relay 13
#define PIN_LED1 12

//PID constants
double kp = 2;
double ki = 5;
double kd = 1;


double output;

// CLASS VARIABLES DECLARATION
//Passes data to the class constructor

Blinker blink1 = Blinker(PIN_LED1, 100, 100);
ReadSensor sensor1 = ReadSensor(PIN_Anologue, 100);
RelayControl Relay1(PIN_Relay,300);
PID_Control PID1;

void setup(){
      //sets the serial monitor to 9600 baud rate
        Serial.begin(9600);
        
        //pinMode(PIN_Relay, OUTPUT);
}   
 
void loop(){
     
        unsigned long CurrentTime = millis();
        bool ONorOFF;

       //Condition to set the Relay on or Off
        if(sensor1.getVoltage()< output){
        ONorOFF = 1;
        }
        else
        ONorOFF = 0;

       //calls the Class functions
        sensor1.ReadSensorInput();
        blink1.check(CurrentTime);
        Relay1.setRelay(CurrentTime,ONorOFF);
        
        double input = sensor1.getVoltage(); //read from Light Sensor connected to A0
        PID1.computePID(input,CurrentTime);//recieves a output from the PID Controller
        output = PID1.getPID_Outout();
        
 Serial.print("X ,"); Serial.print(output); Serial.print(" ");
   Serial.println(" ");

}
 /*
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
}*/
