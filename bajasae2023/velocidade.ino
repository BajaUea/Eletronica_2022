void RPMmotor()
{
  pulsosRPM++; // Função chamada no pino de interrupção
}

void motor(){
      if (millis() - timeold >= 200){
    //Desabilita interrupcao durante o calculo
    detachInterrupt(pinRPM);
    //(1 mim)/pulsos por volta)/tempo atual - tempo da ultima vez) * npulsos
    //hz = (60 * 1000 / pulsos_por_volta ) / (millis() - timeold) * pulsos;
    RPM = ((60 * 200 * 5)/2) / (millis() - timeold) * pulsosRPM;
    timeold = millis();
    pulsos = 0;
    
    //filtro
    //filtrado = moving_average();
     
    
    //Mostra o valor de RPM no serial monitor

    //Habilita interrupcao
    attachInterrupt(pinRPM, RPMmotor, FALLING);
  }
}

// --- Interrupção ---
void contador()
{
  //Incrementa contador
  pulsos++;
}


void velocidade(){
  if (millis() - timeold >= 200){
    //Desabilita interrupcao durante o calculo
    detachInterrupt(pRoda);
    //(1 mim)/pulsos por volta)/tempo atual - tempo da ultima vez) * npulsos
    //hz = (60 * 1000 / pulsos_por_volta ) / (millis() - timeold) * pulsos;
    rpm = ((60 * 200 * 5.0)/pulsos_por_volta) / (millis() - timeold) * pulsos;
    timeold = millis();
    pulsos = 0;
    
    //filtro
    //filtrado = moving_average();
     
    
    //Mostra o valor de RPM no serial monitor
    //Habilita interrupcao
    attachInterrupt(pRoda, contador, FALLING);
  }
}
