//function for Sending data
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) { 
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void espnow_setup() {
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

// Register peer
  esp_now_peer_info_t peerInfo;
  memset(&peerInfo, 0, sizeof(peerInfo));
  for (int ii = 0; ii < 6; ++ii )
  {
    peerInfo.peer_addr[ii] = (uint8_t) broadcastAddress[ii];
  }
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  // Add peer
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }

  
  esp_now_register_send_cb(OnDataSent);

}

void espnow_loop() 
{ 
  if (millis() - telemetria_millis >= 600) {
    jsondata = "";  //clearing String after data is being sent
    
    doc["temp_obj"] = temperaturaObjeto; 
    doc["temp_amb"] = temperaturaInterna;

    doc["rpm"] = rpm;
    doc["RPM"] = RPM;
    doc["Tanque_nivel"] = Tanque_nivel;
    serializeJson(doc, jsondata);  //Serilizing JSON
  
    esp_now_send(broadcastAddress, (uint8_t *) jsondata.c_str(), sizeof(jsondata) + 2);  //Sending "jsondata"  
    Serial.println(jsondata); 
    jsondata = "";  
    telemetria_millis = millis();
  }                                                
}
