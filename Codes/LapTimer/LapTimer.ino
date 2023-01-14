const int buttonPin = 19; 
unsigned long int lastDebounceTime = 0;  // the last time the output pin was toggled
int debounceDelay = 50;  
int buttonState= LOW;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
unsigned long int tempo_inicio = 0;
unsigned long int tempo_fim = 0;
bool LapState = false;
String currentlap = "00:00.00";
String lastlap = "00:00.00";
String bestlap = "00:00.00";
unsigned long int bestlap_counter = 100000000;
unsigned long int lastlap_counter = 0;
unsigned long int Sec, Min, Millisec;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);

}

void loop() {
  laptimer_loop();

}
