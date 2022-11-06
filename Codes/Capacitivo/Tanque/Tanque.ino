void IRAM_ATTR funcao_ISR()
{
  bool status_1 = digitalRead(Sinal_1);
  bool status_2 = digitalRead(Sinal_2);
  if(status_1 == HIGH && status_2 == HIGH) result = 2;
  else if (status_1 == HIGH && status_2 == LOW) result = 1;
  else if (status_1 == LOW && status_2 == LOW) result = 0;

}

const int Sinal_1 = 8;
const int Sinal_2 = 12;
int result = 0;

void setup(){
  pinMode(Sinal_1, INPUT); //DEFINE O PINO COMO ENTRADA
  pinMode(Sinal_2, INPUT); //DEFINE O PINO COMO ENTRADA
  attachInterrupt (Sinal_1, funcao_ISR, CHANGE); //Interrupção para ler pulso RPM
  attachInterrupt (Sinal_2, funcao_ISR, CHANGE); //Interrupção para ler pulso RPM
 
}


void loop(){
}
