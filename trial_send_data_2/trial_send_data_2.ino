#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

//setting jaringan
const char* ssid = "free_internet";
const char* password = "aditadit";
const char* host = "192.168.43.98";

float iroom_temp = random(250, 400);
float iwater_temp = random(250, 400);
float ihumidity = random(700, 750);
float iflow = random(100, 200);
float ipH = random (70,80);
float iwater_level = random (700, 1000);

float room_temp;
float water_temp;
float humidity;
float flow;
float pH;
float water_level;

void setup() {
  Serial.begin(9600);

  //setting koneksi wifi
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
  
  // print a random number
  room_temp = iroom_temp/10;
  water_temp = random(250, 400);
  humidity = random(700, 750);
  flow = random(100, 200);
  pH = random (70,80);
  water_level = random (700, 1000);
  
  Serial.print("Room Temp. : ");
  Serial.println(room_temp/10);
  Serial.print("Water Temp.: ");
  Serial.println(water_temp/10);
  Serial.print("Humidity: ");
  Serial.println(humidity/10);
  Serial.print("Flow Water: ");
  Serial.println(flow/10);
  Serial.print("ph: ");
  Serial.println(pH/10);
  Serial.print("Water Level: ");
  Serial.println(water_level/10);
  
  //proses cek koneksi ke server
  WiFiClient client;
  const int httpPort = 80;
  if(!client.connect(host,httpPort))
  {
    Serial.println("Connection Failed");
    return;
  }

  //proses pengiriman data ke server
  String Link;
  HTTPClient http;
  Link = "http://" + String(host) +"/hidroponik2/kirimdata.php?suhu=" + room_temp/10
  + "&water_temp=" + water_temp/10 + "&lembab=" + humidity/10
  + "&flow=" + flow/10 + "&ph=" + pH/10 + "&water_level=" + water_level/10;
  
  //eksekusi link
  http.begin(client,Link);
  
  //mode GET
  http.GET();

  //baca respon
  String respon = http.getString();
  Serial.println(respon);
  http.end();
  
  delay(5000);
}
