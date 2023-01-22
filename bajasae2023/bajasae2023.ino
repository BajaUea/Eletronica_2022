//RPM da Roda
float           rpm, hz;
volatile byte pulsos;
unsigned long timeold;
unsigned int pulsos_por_volta = 50;
int pRoda = 2;

// Capacitivo
const int Capacitivo_1 = 25;
const int Capacitivo_2 = 26;
int Tanque_nivel = 0;
int Tanque_display = 25;

// LapTimer
const int buttonPin = 12;
unsigned long int lastDebounceTime = 0;  // the last time the output pin was toggled
int debounceDelay = 50;
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
unsigned long int tempo_inicio = 0;
unsigned long int tempo_fim = 0;
bool LapState = false;
String currentlap = "00:00.00";
String lastlap = "00:00.00";
String bestlap = "00:00.00";
unsigned long int bestlap_counter = 100000000;
unsigned long int lastlap_counter = 0;
unsigned long int Sec, Min, Millisec;
bool tempo_inicio_flag, tempo_fim_flag;

// Display
#include <HardwareSerial.h>
HardwareSerial DisplayPort(2);  //if using UART2

//rpm motor
int pinRPM = 19; // Pino de interrupção para rotação do motor
volatile byte pulsosRPM = 0; //contador de pulsos para rpm
float RPM = 0; //frequencia de rotacoes em RPM

//temperatura cvt
#include <SparkFunMLX90614.h> // SparkFunMLX90614 Arduino library
#include <Wire.h>
IRTherm therm; // Create an IRTherm object to interact with throughout
float temperatura = 0;
unsigned long ultimoTempo = 0;

void setup() {
  Serial.begin(115200);
  
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt (buttonPin, ISR_timer, CHANGE); //Interrupção para ler pulso RPM

  //RPM roda
  pinMode(pRoda, INPUT);
  //Interrupcao 1 - pino digital 3
  //Aciona o contador a cada pulso
  attachInterrupt(pRoda, contador, FALLING);
  pulsos = 0;
  rpm = 0;
  timeold = 0;

  //capacitivo
  pinMode(Capacitivo_1, INPUT);
  pinMode(Capacitivo_2, INPUT);
  attachInterrupt (Capacitivo_1, ISR_capacitivo1, CHANGE);
  attachInterrupt (Capacitivo_2, ISR_capacitivo2, CHANGE);

  //display
  DisplayPort.begin(9600, SERIAL_8N1, 16, 17);

  //rpm motor
  pinMode(pinRPM, INPUT);
  attachInterrupt (pinRPM, RPMmotor, RISING); //Interrupção para ler pulso RPM
}


void loop() {
  velocidade();
  tempInfra();
  laptimer_loop();
  display_loop();
  Serial.print(rpm);
  Serial.print("\t");
  Serial.print(RPM);
  Serial.print("\t");
  Serial.print(temperatura);
  Serial.print("\t");
  Serial.println(Tanque_nivel);
}
