  void conectar_dinamico(String ssid, String pass)
{
  Serial.begin(115200);
  Serial.println();

  WiFi.begin(ssid, pass);

  Serial.print("Conectando");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Conectado, dirección IP: ");
  Serial.println(WiFi.localIP());
}

void conectar_estatico(String ssid, String pass, IPAddress staticIP, IPAddress gateway, IPAddress subnet)
{
  Serial.begin(115200);
  Serial.println();

  WiFi.begin(ssid, pass);   // RED WIFI 
  
  WiFi.config(staticIP, gateway, subnet);

  Serial.print("Conectando");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Conectado, dirección IP: ");
  Serial.println(WiFi.localIP());
}