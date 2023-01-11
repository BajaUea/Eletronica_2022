#include <esp_now.h>
#include <WiFi.h>

// Structure example to receive data
// Must match the sender structure
typedef struct struct_message {
  int tempo;
  double temp_obj;
  double temp_amb; 
  float RPM;
  float VEL;
  int capacitivo;
  int button;
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
  Serial.print(myData.capacitivo);
  Serial.print(" , ");
  Serial.print(myData.button);
  Serial.println();
}
 
void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);
  
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
