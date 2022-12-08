//variaveis pra leitura
int           rpm, hz;
volatile byte pulsos;
unsigned long timeold;

unsigned int pulsos_por_volta = 50;

int pRoda = 3;

//variavei do filtro
#define n 5//numero de pontos da media movel
long moving_average();//funçao para o filtro
int       original,          //recebe o valor de AN0
          filtrado;          //recebe o valor original filtrado
int       numbers[n];        //vetor com os valores para média móvel


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
