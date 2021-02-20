
// CLASS VARIABLES DECLARATION
//Passes data to the class constructor
Blinker blink1 = Blinker(PIN_LED1, 1000, 1000);
DepthSensor Depth1 = DepthSensor(PIN_Anologue, 1000);

void setup() {
//sets the serial monitor to 9600 baud rate
Serial.begin(9600);

}

void loop() {
//calls blinking led program  
  blink1.check();
//calls Depth sensor program  
  Depth1.DataConvert();

  //Prints out the resulting voltage to the screen on the serial monitor
   Serial.print("X ,"); Serial.print(Depth1.getvoltage()); Serial.print(" ");
   Serial.println(" ");
}
