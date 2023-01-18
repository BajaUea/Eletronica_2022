void laptimer_loop() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

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
    int lastlap_counter = tempo_fim - tempo_inicio;
    tempo_fim = 0;
    tempo_inicio = 0;
    
  }
  
  if (LapState == true) {
    Millisec = ((millis()-tempo_inicio)%1000);
    Sec = ((millis()-tempo_inicio)/1000)%60;
    Min = ((millis()-tempo_inicio)/60000)%60;
    if (Min < 10) {
      if (Sec < 10){
      currentlap = String('0' + Min + ':' + '0' + Sec + '.' + Millisec);
      }
      else currentlap = String('0' + Min + ':' + Sec + '.' + Millisec);
    }
    else if (Sec < 10) currentlap = String(Min + ':' + '0' + Sec + '.' + Millisec);
    else currentlap = String(Min + ':' + Sec + '.' + Millisec);
  }
  else currentlap = "00:00.00";
  
}
