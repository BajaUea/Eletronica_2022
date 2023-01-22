void display_loop(){
  DisplayPort.print("tach.pic=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  DisplayPort.print(map(RPM, 0, 8000, 0, 208));  // This is the value you want to send to that object and atribute mention before.
  DisplayPort.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  DisplayPort.write(0xff);
  DisplayPort.write(0xff);

  DisplayPort.print("rpm.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  DisplayPort.print(RPM);  // This is the value you want to send to that object and atribute mention before.
  DisplayPort.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  DisplayPort.write(0xff);
  DisplayPort.write(0xff);

  DisplayPort.print("fuel.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  DisplayPort.print(Tanque_display);  // This is the value you want to send to that object and atribute mention before.
  DisplayPort.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  DisplayPort.write(0xff);
  DisplayPort.write(0xff);

  DisplayPort.print("vel.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  DisplayPort.print(int(rpm*100));  // This is the value you want to send to that object and atribute mention before.
  DisplayPort.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  DisplayPort.write(0xff);
  DisplayPort.write(0xff);

  DisplayPort.print("lastlap.txt=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  DisplayPort.print("\"" + lastlap + "\"");  // This is the value you want to send to that object and atribute mention before.
  DisplayPort.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  DisplayPort.write(0xff);
  DisplayPort.write(0xff);

  DisplayPort.print("bestlap.txt=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  DisplayPort.print("\"" + bestlap + "\"");  // This is the value you want to send to that object and atribute mention before.
  DisplayPort.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  DisplayPort.write(0xff);
  DisplayPort.write(0xff);

  DisplayPort.print("currentlap.txt=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  DisplayPort.print("\"" + currentlap + "\"");  // This is the value you want to send to that object and atribute mention before.
  DisplayPort.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  DisplayPort.write(0xff);
  DisplayPort.write(0xff);
}
