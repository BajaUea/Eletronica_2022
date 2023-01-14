void laptimer_loop() {
  // read the state of the switch into a local variable:
  int reading = !digitalRead(buttonPin);
  

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
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
  }
  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;

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
  //Serial.println("lastlap:" + lastlap + " " + "currentlap:" + currentlap + " " + "bestlap:" + bestlap);
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
