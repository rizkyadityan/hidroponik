#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

//setting jaringan
const char* ssid = "ALASKA";
const char* password = "polarbear001";
const char* host = "hidroponikadit.000webhostapp.com";

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   
   WiFi.begin(ssid, password);
  //cek koneksi wifi
  while(WiFi.status() != WL_CONNECTED)
  {
    //nodemcu coba koneksi
    Serial.print(".");
    delay(500);
  }

  
  Serial.println("WiFi Connected");
}

String strID ="adit";
void loop() {

//id kartu dan yang akan dibaca ke database
  Serial.println("Reading Parameter....");
  baca_database();
  delay(1000);
}

void baca_database()
{
    WiFiClient client;
    const int httpPort = 80;
   
   if (!client.connect(host,httpPort)) {
      Serial.println("Gagal Konek");
      return;
    }

  String Link;
  HTTPClient http;
//Link = "http://" + String(host) +"/rfid/rfidread.php?idcard=" + strID;
  Link = "http://" + String(host) +"/read_data.php?idcard=";
  
  //eksekusi link
  http.begin(client,Link);
  
  //mode GET
  http.GET();

  //baca respon
  String respon = http.getString();
  Serial.println(respon);
  http.end();
} 
