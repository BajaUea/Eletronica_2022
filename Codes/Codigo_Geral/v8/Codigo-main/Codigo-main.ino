#include <Wire.h>

// LapTimer
<<<<<<< HEAD
const int buttonPin = 35; 
=======
const int buttonPin = 19; 
>>>>>>> 9c2cc0799ed13300785434c8dff70cd4770c357a
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
<<<<<<< HEAD
unsigned long intlastlap_counter = 0;
unsigned long int Sec, Min, Millisec;

// Capacitivo
const int Capacitivo_1 = 25;
const int Capacitivo_2 = 26;
=======
unsigned long int lastlap_counter = 0;
unsigned long int Sec, Min, Millisec;
//
//// Capacitivo
const int Capacitivo_1 = 16;
const int Capacitivo_2 = 18;
>>>>>>> 9c2cc0799ed13300785434c8dff70cd4770c357a
int Tanque_nivel = 0;
int Tanque_display = 25;

// espnow
#include <esp_now.h>
#include <WiFi.h>

// REPLACE WITH YOUR RECEIVER MAC Address
// 94:B5:55:2C:F5:EC
uint8_t broadcastAddress[] = {0x94, 0xB5, 0x55, 0x2D, 0x0B, 0x08};

typedef struct struct_message {
  float RPM;
  float VEL;
  int capacitivo;
} struct_message;

struct_message myData;
esp_now_peer_info_t peerInfo;

// Display
#include <SoftwareSerial.h>
SoftwareSerial SerialPort(16, 17);



// RPM E VELOCIDADE
<<<<<<< HEAD
#include <SoftwareSerial.h>
#define pinRPM 14 // Pino de interrupção para rotação do motor
float PERIMETRO_RODA = 0.26;
=======
#define pinVEL 15 // // Pino de interrupção para rotação da roda
#define pinRPM 17 // Pino de interrupção para rotação do motor
>>>>>>> 9c2cc0799ed13300785434c8dff70cd4770c357a

unsigned long Velocidade_millisInicial = 0; //tempo inicial para velocidade 
volatile byte pulsosVEL = 0; //contador de pulsos para velocidade
volatile byte pulsosRPM = 0; //contador de pulsos para rpm
float RPM = 0; //frequencia de rotacoes em RPM
float VEL = 0; //velocidade em km/h
const double PERIMETRO_RODA = 1.72161199;
int           rpm, hz;
volatile byte pulsos;
unsigned long timeold;
unsigned int pulsos_por_volta = 50;
int pRoda = 3;

void setup() {
<<<<<<< HEAD
 Serial.begin(115200);
=======
 SerialPort.begin(9600);
 Serial.begin(9600);
>>>>>>> 9c2cc0799ed13300785434c8dff70cd4770c357a
 espnow_setup();
 capacitivo_setup();
 pinMode(buttonPin, INPUT_PULLUP);


<<<<<<< HEAD
 
//   pinMode(pinVEL, INPUT);
//  attachInterrupt (pinVEL, tacometro, RISING); //Interrupção para ler pulso da velocidade

 pinMode(pinRPM, INPUT);
 attachInterrupt (pinRPM, RPMmotor, RISING); //Interrupção para ler pulso RPM
 
//attachInterrupt (digitalPinToInterrupt(pinRPM), RPMmotor, RISING); //Interrupção para ler pulso do RPM
  pinMode(pRoda, INPUT);
  attachInterrupt(pRoda, tacometro, RISING); //Interrupção para ler pulso da velocidade
=======
 pinMode(pinVEL, INPUT);
 attachInterrupt (pinVEL, tacometro, RISING); //Interrupção para ler pulso da velocidade
>>>>>>> 9c2cc0799ed13300785434c8dff70cd4770c357a

}

void loop() {
  velocidade();
<<<<<<< HEAD
  //espnow_loop();
  display_loop();


=======
  espnow_loop();
  laptimer_loop();
  display_loop();
>>>>>>> 9c2cc0799ed13300785434c8dff70cd4770c357a
}
