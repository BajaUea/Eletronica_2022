int variable1 = 0;  // This is a simple variable to keep increasing a number to have something dynamic to show on the display.
#include <HardwareSerial.h>

HardwareSerial SerialPort(2);  //if using UART2

void setup() {  // Put your setup code here, to run once:
  
//  SerialPort.begin(9600);  // Start SerialPort comunication at baud=9600. For Arduino mega you would have to add a
//                       // number (example: "SerialPort1.begin(9600);").
//                       // If you use an Arduino mega, you have to also edit everything on this sketch that
//                       // says "SerialPort" and replace it with "SerialPort1" (or whatever number you are using).


  SerialPort.begin(9600, SERIAL_8N1, 16, 17);
  Serial.begin(115200);

  



}  // End of setup





void loop() {  // Put your main code here, to run repeatedly:

  variable1++;  // Increase the value of the variable by 1.
  if(variable1 == 200){  // If the variable reach 201...
    variable1 = 0;  // Set the variable to 0 so it starts over again.
  }





  // We are going to send the variable value to the object called n0:
  // After the name of the object you need to put the dot val because val is the atribute we want to change on that object.
  SerialPort.print("temp.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  SerialPort.print(variable1);  // This is the value you want to send to that object and atribute mention before.
  SerialPort.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  SerialPort.write(0xff);
  SerialPort.write(0xff);





  // We are going to update the progress bar to show the value of the variable.
  // The progress bar range goes from 0 to 100, so when the variable is greater than 100, the progress bar will keep showing full (100%).
  SerialPort.print("fuel.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  SerialPort.print(variable1);  // This is the value you want to send to that object and atribute mention before.
  SerialPort.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  SerialPort.write(0xff);
  SerialPort.write(0xff);





  // We are going to update the gauge to show the value of the variable.
  // But instead of updating the gauge directly, we are going to send the value to a variable called va0 on the nextion display.
  // On the nextion display we have a code on the timer (tm0) that compares the variable value and the gauge value, and updates the gauge only when they are different.
  // The gauge range goes from 0 (pointing to the left) to 359.
  SerialPort.print("tach.pic=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  SerialPort.print(variable1);  // This is the value you want to send to that object and atribute mention before.
  Serial.print("tach.pic=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.println(variable1);  // This is the value you want to send to that object and atribute mention before.
  SerialPort.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  SerialPort.write(0xff);
  SerialPort.write(0xff);




}   // End of loop
