void laptimer_loop() {
  
  if (button_flag){
    button_flag = false;
    if ((millis() - lastDebounceTime) > debounceDelay) {
      lastDebounceTime = millis();
      if (LapState == false) {
        LapState = true;
        tempo_inicio = millis();
      }
      else if (LapState == true) {
        LapState = false;
        tempo_fim = millis();
        }
    }
  }

  if (tempo_fim > tempo_inicio){
    lastlap_counter = tempo_fim - tempo_inicio;
    lastlap = format_timer(lastlap_counter);
    
    if (lastlap_counter < bestlap_counter) {
      bestlap_counter = lastlap_counter;
      bestlap = lastlap;
      }
    tempo_fim = 0;
    tempo_inicio = 0;
  }
  
  if (LapState == true) {
    currentlap = format_timer(millis()-tempo_inicio);
  }
  else currentlap = "00:00.00";
  Serial.println("lastlap:" + lastlap + " " + "currentlap:" + currentlap + " " + "bestlap:" + bestlap + digitalRead(buttonPin));

  
}

String format_timer(int total_millis){
    Millisec = (total_millis%1000)/10;
    Sec = (total_millis/1000)%60;
    Min = (total_millis/60000)%60;
    if (Min < 10) {
      if (Sec < 10){
        if (Millisec < 10) return String(String('0') + Min + String(':') + Sec + String('.') + String('0') + Millisec);
        return String(String('0') + Min + String(':') + String('0') + Sec + String('.') + Millisec);
      }
      else if (Millisec < 10) return String(String('0') + Min + String(':') + Sec + String('.') + String('0') + Millisec);
      else return String(String('0') + Min + String(':') + Sec + String('.') + Millisec);
    }
    else if (Sec < 10) return String(Min + String(':') + String('0') + Sec + String('.') + Millisec);
    else if (Millisec < 10) return String(Min + String(':') + Sec + String('.') + String('0') + Millisec);
    else return String(Min + String(':') + Sec + String('.') + Millisec);
  }

void ISR_timer(){
  button_flag = true;
  }
