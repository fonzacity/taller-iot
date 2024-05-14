#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "datos.h"

/* Configuración de WiFi e IP en "datos.h"

String ssid = "";
String pass = "";

IPAddress staticIP(192,168,1,-);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);                                        

*/

ESP8266WebServer placa(80); // Servidor HTTP en el puerto 80

int rele = 4;               // GPIO4 = D2 => Relé de la lámpara

int status = 0;             // Variable para conocer el estado del relé (lámpara) 0-apagada / 1-encendida

void setup()
{
  // LED_BUILTIN --> Indica que ESP8266 está funcionando
  pinMode(LED_BUILTIN,OUTPUT);    // LED_BUILTIN corresponde a D4 en NodeMCU  
  digitalWrite(LED_BUILTIN,LOW);  

  // Control de la lámpara
  pinMode(rele,OUTPUT);           
  digitalWrite(rele,HIGH);      // Relé de lógica negativa --> Lámpara apagada

  // Conexión a WiFi: dos opciones IP dinámica o IP estática
  // conectar_dinamico(ssid, pass);
  conectar_estatico(ssid, pass, staticIP, gateway, subnet);

  // Inicia servidor http
  iniciar(placa);
  
  // Indica sistema operativo --> Parpadeo 4 veces de LED_BUILTIN
  confirmacion();   
  
}

void loop() 
{
  // Gestiona las peticiones http
  placa.handleClient();
}

// Parpadeo 4 veces de LED_BUILTIN
void confirmacion() {
  for (int i = 0; i < 5; i++) { 
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
  }
}
