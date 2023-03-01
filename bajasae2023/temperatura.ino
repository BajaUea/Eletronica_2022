void iniciaInfra(){
    // Initialize thermal IR sensor
  if (!therm.begin()){
    Serial.print("erro na inicialização infravermelho");
  }
  therm.setUnit(TEMP_C); // Set the library's units to Farenheit
  // Alternatively, TEMP_F can be replaced with TEMP_C for Celsius or TEMP_K for Kelvin.
}


void tempInfra() {
  if(millis() - ultimoTempo >= 200){
    ultimoTempo = millis();
    iniciaInfra();
    if (therm.read()){ // On success, read() will return 1, on fail 0.
      temperaturaObjeto = therm.object()+10;
      temperaturaInterna = therm.ambient();
      /*Serial.print("Object: " + String(temperatura, 2));
      Serial.write('°'); // Degree Symbol
      Serial.println("C");
      Serial.print("Ambient: " + String(therm.ambient(), 2));
      Serial.write('°'); // Degree Symbol
      Serial.println("C");
      Serial.println();*/
    }
  }
}
