void Vel_Setup(){
  pinMode(pRoda, INPUT);

  //Interrupcao 1 - pino digital 3
  //Aciona o contador a cada pulso
  attachInterrupt(pRoda, tacometro, FALLING);
  pulsosVEL = 0;
  int rpmRoda = 0;
  timeold = 0;
}

void velocidade() {
    if (millis() - timeold >= 200){
    //Desabilita interrupcao durante o calculo
    detachInterrupt(pRoda);
    //(1 mim)/pulsos por volta)/tempo atual - tempo da ultima vez) * npulsos
    //hz = (60 * 1000 / pulsos_por_volta ) / (millis() - timeold) * pulsos;
    rpm = ((60 * 200 * 5)/pulsos_por_volta) / (millis() - timeold) * pulsos;
    timeold = millis();
    pulsos = 0;
    
    //filtr
    //filtrado = moving_average();
     
    
    //Mostra o valor de RPM no serial monitor
    //Habilita interrupcao
    Serial.println(rpm);
    attachInterrupt(pRoda, tacometro, FALLING);
  }
}

void tacometro()
{
  pulsosVEL++; // Função chamada no pino de interrupção
}

void RPMmotor()
{
  pulsosRPM++; // Função chamada no pino de interrupção
}

