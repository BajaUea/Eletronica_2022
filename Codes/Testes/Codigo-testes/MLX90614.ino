
void mlx_loop(){
  if((millis()-Temp_millisInicial) > 1000){
    temp_amb = mlx.readAmbientTempC();
    temp_obj = mlx.readObjectTempC();
    Temp_millisInicial = millis();
    Serial.print(temp_obj);
    Serial.print(" , ");
    Serial.print(temp_amb);
    Serial.print(" , ");
  }
}