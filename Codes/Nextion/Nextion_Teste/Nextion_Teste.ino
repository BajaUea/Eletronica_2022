int variable1 = 0;  // This is a simple variable to keep increasing a number to have something dynamic to show on the display.
#include <SoftwareSerial.h>

SoftwareSerial SerialPort(16, 17);  //if using UART2

void setup() {  // Put your setup code here, to run once:
  
//  SerialPort.begin(9600);  // Start SerialPort comunication at baud=9600. For Arduino mega you would have to add a
//                       // number (example: "SerialPort1.begin(9600);").
//                       // If you use an Arduino mega, you have to also edit everything on this sketch that
//                       // says "SerialPort" and replace it with "SerialPort1" (or whatever number you are using).


  SerialPort.begin(9600);
  Serial.begin(115200);

  



}  // End of setup





void loop() {  // Put your main code here, to run repeatedly:

  variable1++;  // Increase the value of the variable by 1.
  if(variable1 == 200){  // If the variable reach 201...
    variable1 = 0;  // Set the variable to 0 so it starts over again.
  }
  display_loop();







}   // End of loop
