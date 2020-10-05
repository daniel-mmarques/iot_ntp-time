#include <WiFiUdp.h>
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "VIVOFIBRA-9B6D";
const char* password = "EAEA8F9B6D";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP , "a.st1.ntp.br", -3 * 3600 , 60000);

char diasSemana[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int buscarDia () {
  timeClient.begin();
  timeClient.update();
  int dia =  timeClient.getDay();
  return dia; 
}

int buscarHora () {
  timeClient.begin();
  timeClient.update();
  int hora =  timeClient.getHours();
  return hora; 
}

int buscarMinuto () {
  timeClient.begin();
  timeClient.update();
  int minuto =  timeClient.getMinutes();
  return minuto; 
}

int buscarSegundo () {
  timeClient.begin();
  timeClient.update();
  int segundo =  timeClient.getSeconds();
  return segundo; 
}

String buscarTempoFormatado () {
  timeClient.begin();
  timeClient.update();
  String formattedTime =  timeClient.getFormattedTime();
  return formattedTime; 
}

void setup() {
  
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    
        delay(500);
        Serial.print(".");
        
  }

}

void loop() {
  
  Serial.print("Dia : ");
  Serial.println(diasSemana[buscarDia()]);

  delay(1000);

  Serial.print("Hora : ");
  Serial.println(buscarHora());

  delay(1000);

  Serial.print("Minuto : ");
  Serial.println(buscarMinuto());

  delay(1000);

  Serial.print("Segundo : ");
  Serial.println(buscarSegundo());

  delay(1000);

  Serial.print("Tempo Formatado : ");
  Serial.println(buscarTempoFormatado());

  delay(1000);
}
