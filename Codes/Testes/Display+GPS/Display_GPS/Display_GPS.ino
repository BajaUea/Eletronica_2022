#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>
#include <HardwareSerial.h>

HardwareSerial SerialPort(2);  //if using UART2
int variable1 = 0;  // This is a simple variable to keep increasing a number to have something dynamic to show on the display.

static const int RXPin = 3, TXPin = 1;
static const uint32_t GPSBaud = 9600;
unsigned long previousMillis = 0;     // will store last time LED was updated
const long interval = 1000;           // interval at which to blink (milliseconds)
unsigned long currentMillis = 0;

// The TinyGPSPlus object
TinyGPSPlus gps;

SoftwareSerial ss(RXPin, TXPin);
unsigned long last = 0UL;

void setup() {
  Serial.begin(115200);
  ss.begin(GPSBaud);
  SerialPort.begin(9600, SERIAL_8N1, 16, 17);


}

void loop() {
  variable1++;  // Increase the value of the variable by 1.
  if(variable1 == 200){  // If the variable reach 201...
    variable1 = 0;  // Set the variable to 0 so it starts over again.
  }
  
  if (ss.available() > 0){
    gps.encode(ss.read());
    currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {

      previousMillis = currentMillis;
      Serial.print(gps.speed.kmph());
      Serial.print(" ");
      SerialPort.print("vel.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
      SerialPort.print(gps.speed.kmph());  // This is the value you want to send to that object and atribute mention before.
      SerialPort.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
      SerialPort.write(0xff);
      SerialPort.write(0xff);

      SerialPort.print("tach.pic=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
      SerialPort.print(gps.speed.kmph());  // This is the value you want to send to that object and atribute mention before.
      SerialPort.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
      SerialPort.write(0xff);
      SerialPort.write(0xff);
      
      if (gps.charsProcessed() < 10)
        Serial.println(F("WARNING: No GPS data.  Check wiring."));
    }
  }
  SerialPort.print("temp.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  SerialPort.print(variable1);  // This is the value you want to send to that object and atribute mention before.
  SerialPort.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  SerialPort.write(0xff);
  SerialPort.write(0xff);
  
}
