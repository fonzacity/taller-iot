# Taller IoT
El proyecto consiste en una maqueta de IoT en la que se:
* Controla y monitoriza lámparas
* Monitoriza sensores de humedad y temperatura


## Componentes IoT
Los componente IoT están conectados a una red WiFi mediante el chip **ESP8266**. Se ha empleado la plataforma *NodeMCU 1.0 (v2)* de Amica que emplea el módulo *ESP8266 ESP-12E*.

Las placa se configuran como **servidores http** conectados en una misma red **WiFi**:

* Para la gestión de la conexión a la red Wifi se emplea la biblioteca **<ESP8266WiFi.h>.**

* Para la configuración como servidor web se emplea la biblioteca **<ESP8266WebServer.h>**.

El código se ha estructurado en cuatro archivos para facilitar su comprensión:

| Archivo  | Descripción |
| ------------- | ------------- |
| *lampara.ino* / *dht.ino* | Archivo principal  |
| *wifi.ino*  | Gestión de la conexión WiFi  |
| *servidor.ino* | Gestión del servidor web |
| *datos.h* | Datos de la red (SSID y pass) y asignación de la dirección IP  |


Para clarificar el código se han implementado en el archivo wifi.ino dos funciones para la conexión a la red WiFi. Estas funciones son:
* conectar_dinamico()
* conectar_estatico()

Comentando y descomentando oportunamente la llamada a estas funciones en el archivo principal (lampara.ino) puede elegirse entre una IP estática o dinámica.

Los datos de la conexión a la red WiFi así como la IP asignada a cada dispositivo están definidas en el archivo “datos.h”.


### Lámparas

El control de la lámpara se realiza mediante un relé conectado al pin **GPIO4**, que en NodeMCU corresponde a **D2**.

El relé empleado es de *lógica negativa* con optoacoplador.


| **Rutas** |**Descripción**|**Response**|
|-----------|---------------|---------|
|/|Sirve una página web muy sencilla, a modo de comprobación de que el servidor funciona | HTML|
| /encender | Cierra el relé (enciende la lámpara) | JSON {“mensaje”:”Encender”} |
| /apagar | Abre el relé (apaga la lámpara) | JSON {“mensaje”:”Apagar”} |
| /estado | Devuelve un el estado del relé (lámpara) | TEXTO PLANO: '0' ó '1'   |



### Sensores de temperatura y humedad

Se emplean sensores de la familia **DHT**. Por defecto se emplea *DHT11*, pero es posible emplear otros modificando el código facilmente.

El sensor emplea la libreria **"<DHT.h>"**

Se conecta el pin DATA del sensor al **GPIO4** del ESP8266, que en NodeMCU corresponde a **D2**. 

| **Rutas** |**Descripción**|**Response**|
|-----------|---------------|---------|
|/|Sirve una página web muy sencilla, a modo de comprobación de que el servidor funciona | HTML|
| /temperatura  | valor de temperatura (en ºC) | TEXTO PLANO |
| 	/humedad | valor de humedad (en %) | TEXTO PLANO |