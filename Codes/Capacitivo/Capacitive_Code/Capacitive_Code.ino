const int pinoSinal = 15; //PINO DIGITAL UTILIZADO PELO SENSOR
const int pinoLed = 2; //PINO DIGITAL UTILIZADO PELO LED
 
void setup(){
  Serial.begin(9600);
  pinMode(pinoSinal, INPUT); //DEFINE O PINO COMO ENTRADA
  pinMode(pinoLed, OUTPUT); //DEFINE O PINO COMO SAÍDA
  digitalWrite(pinoLed, LOW); //LED INICIA DESLIGADOq
}
void loop(){
  if(digitalRead(pinoSinal) == HIGH){ //SE A LEITURA DO PINO FOR IGUAL A LOW, FAZ
          digitalWrite(pinoLed, HIGH); //ACENDE O LED
  }else{ //SENÃO, FAZ
        digitalWrite(pinoLed, LOW); //APAGA O LED
  }
  Serial.println(digitalRead(pinoSinal));
}