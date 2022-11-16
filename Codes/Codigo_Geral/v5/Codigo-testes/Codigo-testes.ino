#include <Wire.h>

// Tempo
int tempo;

// Botão
const int button = 5;
int status_button;

// Capacitivo
const int Capacitivo_1 = 8;
const int Capacitivo_2 = 12;
int capacitivo = 0;

// espnow
#include <esp_now.h>
#include <WiFi.h>

// REPLACE WITH YOUR RECEIVER MAC Address
// 94:B5:55:2C:F5:EC
uint8_t broadcastAddress[] = {0x94, 0xB5, 0x55, 0x2D, 0x0B, 0x08};

typedef struct struct_message {
  int tempo;
  double temp_obj;
  double temp_amb; 
  float RPM;
  float VEL;
  int capacitivo;
  int button;
} struct_message;

struct_message myData;
esp_now_peer_info_t peerInfo;

// Define o endereço utilizado pelo Adaptador I2C
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);

// RPM E VELOCIDADE
#include <SoftwareSerial.h>
#define pinVEL 15 // // Pino de interrupção para rotação da roda
#define pinRPM 17 // Pino de interrupção para rotação do motor

unsigned long Velocidade_millisInicial = 0; //tempo inicial para velocidade 
volatile byte pulsosVEL = 0; //contador de pulsos para velocidade
volatile byte pulsosRPM = 0; //contador de pulsos para velocidade
float RPM = 0; //frequencia de rotacoes em RPM
float VEL = 0; //velocidade em km/h
//const float RAIO_RODA = 0.266;
const double PERIMETRO_RODA = 1.72161199;


// TEMP
#include <SparkFunMLX90614.h> // SparkFunMLX90614 Arduino library
IRTherm therm; // Create an IRTherm object to interact with throughout
double temp_amb; 
double temp_obj; 

void setup() {
  
 Serial.begin(9600);
 button_setup();
 espnow_setup();
 capacitivo_setup();
 
 lcd.begin(20, 4);
 lcd.backlight();
 display_setup();

 
//   pinMode(pinVEL, INPUT);
//  attachInterrupt (pinVEL, tacometro, RISING); //Interrupção para ler pulso da velocidade

 pinMode(pinRPM, INPUT);
 attachInterrupt (pinRPM, RPMmotor, RISING); //Interrupção para ler pulso RPM
 
//attachInterrupt (digitalPinToInterrupt(pinRPM), RPMmotor, RISING); //Interrupção para ler pulso do RPM
  attachInterrupt(digitalPinToInterrupt(pinVEL), tacometro, RISING); //Interrupção para ler pulso da velocidade

}

void loop() {

  tempo = millis();
  tempInfra();
  velocidade();
  espnow_loop();
  display_loop();

  Serial.print(temp_obj);
  Serial.print(" , ");
  Serial.print(temp_amb);
  Serial.print(" , ");
  Serial.print(RPM);
  Serial.print(" , ");
  Serial.print(VEL);
  Serial.println();

}
