void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  // read the input on analog pin A0 and stores in variable sensorValue
int sensorValue = analogRead(A0);

 // Convert the analog reading (from 0 - 1023) to a voltage (0 - 5V) and store it in variable voltage
 float voltage = sensorValue * (5.0 / 1023.0);
 int y = -26*voltage + 68;
 
 //Prints out the resulting voltage to the screen on the serial monitor
 Serial.print("X ,"); Serial.print(voltage); Serial.print(" ");
 Serial.println(" ");Serial.print(y);
}
