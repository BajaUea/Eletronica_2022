void Vel_Setup(){
  pinMode(pRoda, INPUT);

  //Interrupcao 1 - pino digital 3
  //Aciona o contador a cada pulso
  attachInterrupt(1, tacometro, FALLING);
  pulsosVEL = 0;
  rpmRoda = 0;
  timeold = 0;
}

void velocidade()
{
  if (millis() - timeold >= 200)
  {
    noInterrupts();
    float VEL_anterior = VEL;
    // VEL = (pulsosVEL*0.04625*2.0*3.14*RAIO_RODA*3.6); // Calculo da velocidade
    VEL = (pulsosVEL*0.04625*PERIMETRO_RODA*3.6); // Calculo da velocidade
    RPM = (pulsosRPM / 2.0 /*numero de pulsos da curva de onda do motor*/) * 60.0; // Calculo do RPM do motor
    // DISTANCIA += (VEL/3.6); //METROS
    // ACC = (VEL - VEL_anterior);
    pulsosVEL = 0;
    pulsosRPM = 0;

    Velocidade_millisInicial = millis();

    interrupts();
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

void setup() {
  Serial.begin(115200);

}


void loop() {
    if {
    //Desabilita interrupcao durante o calculo
    detachInterrupt(1);
    //(1 mim)/pulsos por volta)/tempo atual - tempo da ultima vez) * npulsos
    //hz = (60 * 1000 / pulsos_por_volta ) / (millis() - timeold) * pulsos;
    rpm = ((60 * 200 * 5)/pulsos_por_volta) / (millis() - timeold) * pulsos;
    timeold = millis();
    pulsos = 0;
    
    //filtro
    original = rpm;
    //filtrado = moving_average();
     
    
    //Mostra o valor de RPM no serial monitor
    Serial.print("RPM = ");
    Serial.println(original);
    //Habilita interrupcao
    attachInterrupt(1, contador, FALLING);
  }
}


long moving_average()
{

   //desloca os elementos do vetor de média móvel
   for(int i= n-1; i>0; i--) numbers[i] = numbers[i-1];

   numbers[0] = original; //posição inicial do vetor recebe a leitura original

   long acc = 0;          //acumulador para somar os pontos da média móvel

   for(int i=0; i<n; i++) acc += numbers[i]; //faz a somatória do número de pontos


   return acc/n;  //retorna a média móvel

 
}
