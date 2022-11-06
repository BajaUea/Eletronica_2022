void capacitivo_setup(){
  
  pinMode(Capacitivo_1, INPUT); //DEFINE O PINO COMO ENTRADA
  pinMode(Capacitivo_2, INPUT); //DEFINE O PINO COMO ENTRADA
  attachInterrupt (Capacitivo_1, funcao_ISR, CHANGE); //Interrupção para ler pulso RPM
  attachInterrupt (Capacitivo_2, funcao_ISR, CHANGE); //Interrupção para ler pulso RPM
 
}

void funcao_ISR()
{
  bool status_1 = digitalRead(Capacitivo_1);
  bool status_2 = digitalRead(Capacitivo_2);
  if(status_1 == HIGH && status_2 == HIGH) capacitivo = 2;
  else if (status_1 == HIGH && status_2 == LOW) capacitivo = 1;
  else if (status_1 == LOW && status_2 == LOW) capacitivo = 0;
}
