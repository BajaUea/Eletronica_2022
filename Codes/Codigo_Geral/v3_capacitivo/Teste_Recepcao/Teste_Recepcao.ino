#include <esp_now.h>
#include <WiFi.h>

// Structure example to receive data
// Must match the sender structure
typedef struct struct_message {
  double temp_obj;
  double temp_amb; 
  float RPM;
  float VEL;
  float DISTANCIA;
  float Gyro_X;
  float Gyro_Y;
  float Gyro_Z;
  float ACC;
  int capacitivo;
  int tempo;
} struct_message;

// Create a struct_message called myData
struct_message myData;

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));

  Serial.print(myData.tempo);
  Serial.print(" , ");
  Serial.print(myData.temp_obj);
  Serial.print(" , ");
  Serial.print(myData.temp_amb );
  Serial.print(" , ");
  Serial.print(myData.VEL);
  Serial.print(" , ");
  Serial.print(myData.RPM);
  Serial.print(" , ");
  Serial.print(myData.DISTANCIA);
  Serial.print(" , ");
  Serial.print(myData.ACC);
  Serial.print(" , ");
  switch (myData.capacitivo) {
    case 0:
      Serial.print("BAIXO");
      Serial.print(" , ");
      break;
    case 1:
      Serial.print("MÉDIO");
      Serial.print(" , ");
      break;
    case 2:
      Serial.print("ALTO");
      Serial.print(" , ");
      break;
  }
  Serial.print(myData.Gyro_X);
  Serial.print(" , ");
  Serial.print(myData.Gyro_Y);
  Serial.print(" , ");
  Serial.print(myData.Gyro_Z);

  Serial.println();
}
 
void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_register_recv_cb(OnDataRecv);
}
 
void loop() {

}
