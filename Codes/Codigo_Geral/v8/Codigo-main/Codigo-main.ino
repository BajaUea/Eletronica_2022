#include <Wire.h>

// Capacitivo
const int Capacitivo_1 = 8;
const int Capacitivo_2 = 12;
int Tanque_nivel = 0;
int Tanque_display = 0;

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
#include <HardwareSerial.h>
HardwareSerial DisplayPort(2);  //if using UART2



// RPM E VELOCIDADE
#include <SoftwareSerial.h>
#define pinVEL 15 // // Pino de interrupção para rotação da roda
#define pinRPM 17 // Pino de interrupção para rotação do motor

unsigned long Velocidade_millisInicial = 0; //tempo inicial para velocidade 
volatile byte pulsosVEL = 0; //contador de pulsos para velocidade
volatile byte pulsosRPM = 0; //contador de pulsos para velocidade
float RPM = 0; //frequencia de rotacoes em RPM
float VEL = 0; //velocidade em km/h
// const double PERIMETRO_RODA = 1.72161199;
int           rpm, hz;
volatile byte pulsos;
unsigned long timeold;
unsigned int pulsos_por_volta = 50;
int pRoda = 3;

void setup() {
 Serial.begin(9600);
 espnow_setup();
 capacitivo_setup();
 SerialPort.begin(9600, SERIAL_8N1, 16, 17);


 
//   pinMode(pinVEL, INPUT);
//  attachInterrupt (pinVEL, tacometro, RISING); //Interrupção para ler pulso da velocidade

 pinMode(pinRPM, INPUT);
 attachInterrupt (pinRPM, RPMmotor, RISING); //Interrupção para ler pulso RPM
 
//attachInterrupt (digitalPinToInterrupt(pinRPM), RPMmotor, RISING); //Interrupção para ler pulso do RPM
  attachInterrupt(digitalPinToInterrupt(pinVEL), tacometro, RISING); //Interrupção para ler pulso da velocidade

}

void loop() {
  velocidade();
  espnow_loop();
  display_loop();

  Serial.print(RPM);
  Serial.print(" , ");
  Serial.print(VEL);
  Serial.println();

}
