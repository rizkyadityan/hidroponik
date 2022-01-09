#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

//setting jaringan
/*const char* ssid = "free_internet";
const char* password = "aditadit";
const char* host = "192.168.43.98";*/
const char* ssid = "RAFANAF18";
const char* password = "Rafanaf180";
const char* host = "192.168.1.12";

long sensor;

void setup() {
  Serial.begin(9600);

  //setting koneksi wifi
  WiFi.hostname("NodeMCU");
  WiFi.begin(ssid, password);

  //cek koneksi wifi
  while(WiFi.status() != WL_CONNECTED)
  {
    //nodemcu coba koneksi
    Serial.print(".");
    delay(500);
  }
  //berhasil konek
  Serial.println("WiFi Connected");
}

void loop() {
  
  // print a random number from 65~80
  sensor = random(70, 75);
  Serial.println(sensor);
  

  //proses cek koneksi ke server
  WiFiClient client;
  if(!client.connect(host,80))
  {
    Serial.println("Connection Failed");
    return;
  }

  //proses pengiriman data ke server
  String Link;
  HTTPClient http;
  //Link = "http://192.168.43.98/hidroponik/kirimdata.php?sensor=" + String(sensor);
  Link = "http://" +String(host) +"/hidroponik/kirimdata.php?sensor=" + String(sensor);
  
  //eksekusi link
  http.begin(client,Link);
  //mode GET
  http.GET();
  http.end();
  
  delay(1000);
}
