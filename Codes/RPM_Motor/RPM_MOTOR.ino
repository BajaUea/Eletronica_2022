/*
   Curso de Arduino e AVR WR Kits Channel
   
   Aula 53 - Frequencímetro com Arduino e LCD
   
    
   Autor: Eng. Wagner Rambo  Data: Fevereiro de 2016
   
   www.wrkits.com.br | facebook.com/wrkits | youtube.com/user/canalwrkits
   
*/

// --- Bibliotecas Auxiliares ---
#include <LiquidCrystal.h> //inclui biblioteca lcd


// --- Mapeamento de Hardware ---
#define inFreq   3  //entrada para medir a frequência no pino digital


// --- Variáveis Globais ---
long freq, counter;
int pulseCount;
boolean pulse;


// --- Configurações Iniciais ---
void setup() 
{
  
  pinMode(inFreq,INPUT);    //Configura como entrada
  
  Serial.begin(9600);
  
  pulse = 0x01;             //Seta variável de controle
  
} //end setup


// --- Loop Infinito ---
void loop() 
{
  
  counter = millis();      //counter recebe o valor do tempo em ms
  
  if(digitalRead(inFreq))  //Entrada de frequência em nível alto?
  {                        //Sim...
  
    if(pulse) pulseCount++;  //incrementa pulseCount se variável de controle for verdadeira
     
    pulse = 0x00;            //limpa variável de controle

  }
  else                     //Não...
  {
    pulse = 0x01;          //Seta variável de controle
  }


  if(counter%500 == 0x00)  //Passaram-se 200 ms?
  {                        //Sim...
    freq = pulseCount*2;   //Atualiza frequência (200 x 5 = 1000ms)
    if(freq>0){
    Serial.println((freq/50.0)*60);
    }
    
    
    pulseCount = 0x00;     //Reinicia contador
  }
  
  
} //end loop
