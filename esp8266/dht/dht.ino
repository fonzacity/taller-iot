#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h> 
#include <DHT.h>    
#include "datos.h"

/* Configuración de WiFi e IP en "datos.h"

String ssid = "";
String pass = "";

IPAddress staticIP(192,168,1,-);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);                                        

*/

#define DHTPIN 4            // GPIO4 = D2 => Datos DHT
#define DHTTYPE DHT11       // Cambiar según sensor DHT11, DHT22, ...
DHT dht(DHTPIN, DHTTYPE);

ESP8266WebServer placa(80); // Servidor HTTP en el puerto 80

// Variable globales para la medida de temperatura y humedad
float temp = 0;             // Medida de la temperatura
float hum = 0;              // Medida de la humedad

void setup()
{
  // LED_BUILTIN --> Indica que ESP8266 está funcionando
  pinMode(LED_BUILTIN,OUTPUT);    // LED_BUILTIN corresponde a D4 en NodeMCU  
  digitalWrite(LED_BUILTIN,LOW);

  // Conexión a WiFi: dos opciones IP dinámica o IP estática
  // conectar_dinamico(ssid, pass);
  conectar_estatico(ssid, pass, staticIP, gateway, subnet);

  // Inicia el sensor de temperatura
  dht.begin();

  // Inicia el servidor http
  iniciar(placa);

  // Indica sistema operativo --> Parpadeo 4 veces de LED_BUILTIN
  confirmacion();
  
}

void loop() 
{
  // Medida de temperatura y humedad
  temp = dht.readTemperature();
  hum = dht.readHumidity();

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
