#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

// Define o endereço utilizado pelo Adaptador I2C
LiquidCrystal_I2C lcd(0x27,20,4);

// RPM E VELOCIDADE
#define pinVEL 33 // // Pino de interrupção para rotação da roda
#define pinRPM 30 // Pino de interrupção para rotação do motor
unsigned long Velocidade_millisInicial = 0; //tempo inicial para velocidade 
volatile byte pulsosVEL = 0; //contador de pulsos para velocidade
volatile byte pulsosRPM = 0; //contador de pulsos para velocidade
float RPM = 0; //frequencia de rotacoes em RPM
float VEL = 0; //velocidade em km/h
const float RAIO_RODA = 0.266;

// TEMP
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
unsigned long Temp_millisInicial = 0; //tempo inicial para temperatura 
double temp_amb; 
double temp_obj; 

// GIROSCOPIO
// Endereco I2C do sensor MPU-6050
const int MPU1 = 0x68;
const int MPU2 = 0x69;

float AccX, AccY, AccZ, AccX2, AccY2, AccZ2;
float GyroX, GyroY, GyroZ, GyroX2, GyroY2, GyroZ2;
float accAngleX, accAngleY, gyroAngleX, gyroAngleY, gyroAngleZ, accAngleX2, accAngleY2, gyroAngleX2, gyroAngleY2, gyroAngleZ2;
float roll, pitch, yaw, roll2, pitch2, yaw2;
float AccErrorX, AccErrorY, GyroErrorX, GyroErrorY, GyroErrorZ;
float elapsedTime, currentTime, previousTime;
int c = 0;
unsigned long int Mpu_millisInicial = 0; // tempo inicial para aceleração

void setup() {
 Serial.begin(9600);

 mlx.begin();
 mpu_setup();

//  lcd.begin(20, 4);
 lcd.init();
 lcd.backlight();

  pinMode(pinVEL, INPUT);
 attachInterrupt (pinVEL, tacometro, RISING); //Interrupção para ler pulso da velocidade
//  attachInterrupt (digitalPinToInterrupt(pinRPM), RPMmotor, RISING); //Interrupção para ler pulso do RPM
 
}

void loop() {
  display();
  mpu_loop();
  mlx_loop();
  velocidade();
}