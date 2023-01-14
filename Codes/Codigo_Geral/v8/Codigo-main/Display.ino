void display_loop(){
  
  SerialPort.print("tach.pic=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  // SerialPort.print(map(RPM, 0, 8000, 0, 208));  // This is the value you want to send to that object and atribute mention before.
  SerialPort.print(60);
  SerialPort.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  SerialPort.write(0xff);
  SerialPort.write(0xff);

//  SerialPort.print("rpm.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
//  SerialPort.print(rpm);  // This is the value you want to send to that object and atribute mention before.
//  SerialPort.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
//  SerialPort.write(0xff);
//  SerialPort.write(0xff);

  SerialPort.print("fuel.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  SerialPort.print(80);  // This is the value you want to send to that object and atribute mention before.
  SerialPort.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  SerialPort.write(0xff);
  SerialPort.write(0xff);

  SerialPort.print("vel.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  SerialPort.print(1 * 100);  // This is the value you want to send to that object and atribute mention before.
  SerialPort.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  SerialPort.write(0xff);
  SerialPort.write(0xff);

  SerialPort.print("lastlap.txt=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  SerialPort.print("\"" + lastlap + "\"");  // This is the value you want to send to that object and atribute mention before.
  SerialPort.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  SerialPort.write(0xff);
  SerialPort.write(0xff);

  SerialPort.print("bestlap.txt=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  SerialPort.print("\"" + bestlap + "\"");  // This is the value you want to send to that object and atribute mention before.
  SerialPort.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  SerialPort.write(0xff);
  SerialPort.write(0xff);

  SerialPort.print("currentlap.txt=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  SerialPort.print("\"" + currentlap + "\"");  // This is the value you want to send to that object and atribute mention before.
  SerialPort.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  SerialPort.write(0xff);
  SerialPort.write(0xff);

}
