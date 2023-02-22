int pRoda = 2;

long int rpm,pulsos,timeold;

float pulsos_por_volta = 50;

// --- Interrupção ---
void contador()
{
  //Incrementa contador
  pulsos++;
}


void setup() {
  Serial.begin(115200);

  pinMode(pRoda, INPUT);

  //Interrupcao 1 - pino digital 3
  //Aciona o contador a cada pulso
  attachInterrupt(1, contador, FALLING);
  pulsos = 0;
  rpm = 0;
  timeold = 0;

}


void loop() {
    if (millis() - timeold >= 200){
    //Desabilita interrupcao durante o calculo
    detachInterrupt(1);
    //(1 mim)/pulsos por volta)/tempo atual - tempo da ultima vez) * npulsos
    //hz = (60 * 1000 / pulsos_por_volta ) / (millis() - timeold) * pulsos;
    rpm = ((60 * 200 * 5.0)/pulsos_por_volta) / (millis() - timeold) * pulsos;
    timeold = millis();
    pulsos = 0;
    
     
    //Mostra o valor de RPM no serial monitor
    Serial.print("RPM = ");
    Serial.println(rpm);
    //Habilita interrupcao
    attachInterrupt(1, contador, FALLING);
  }
}
