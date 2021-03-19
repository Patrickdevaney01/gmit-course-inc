//PID Control class

class PID_Control{

  private:
    double kp = 2;
    double ki = 2;
    double kd = 1;
    double elapsedTime,error,lastError,setPoint = 2,cumError, rateError,output;
    
  public:
    
    void computePID(double inp,unsigned long currentTime){     
           unsigned long previousTime;   
           float out;
           
         elapsedTime = (double)(currentTime -  previousTime);        //compute time elapsed from previous computation
        
         error =  setPoint - inp;                                // determine error
         cumError += error * elapsedTime;                // compute integral
         rateError = (error - lastError)/elapsedTime;   // compute derivative
 
         out = kp*error + ki*cumError + kd*rateError;                //PID output
                        
         this -> output = out; 
         
        lastError = error;                                //remember current error
        previousTime = currentTime;                        //remember current time

}

//function return the PID output
    double getPID_Outout(){
       return output;
    }
  
};
