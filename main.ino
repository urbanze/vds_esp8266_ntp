#include <NTPClient.h>//Biblioteca do NTP.
#include <WiFiUDP.h>//Biblioteca do UDP.
#include <ESP8266WiFi.h>//Biblioteca do WiFi.

WiFiUDP udp;//Cria um objeto "UDP".
NTPClient ntp(udp, "a.st1.ntp.br", -3 * 3600, 60000);//Cria um objeto "NTP" com as configurações.

#define led D4//Define o LED ao pino D4.

String hora;//Váriavel que armazenara o horario do NTP.

void setup()
{
   Serial.begin(9600);//Inicia a comunicação serial.

   pinMode(led, OUTPUT);//Define o pino como saida.
   digitalWrite(led, 1);//Apaga o LED.

   WiFi.mode(WIFI_STA);
   WiFi.begin("SUA REDE", "SUA SENHA");//Conecta ao WiFi.
   delay(2000);//Espera a conexão.

   ntp.begin();//Inicia o NTP.
   ntp.forceUpdate();//Força o Update.
}

void loop()
{
   hora = ntp.getFormattedTime();//Armazena na váriavel HORA, o horario atual.
   Serial.println(hora);//Printa a hora já formatada no monitor.

   if (hora == "19:23:30")//Se a hora atual for igual à que definimos, irá acender o led.
   {
      digitalWrite(led, 0);//Acende
   }

   delay(1000);//Espera 1 segundo.
}
