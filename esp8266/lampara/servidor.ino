void iniciar(ESP8266WebServer& placa)
{
  placa.begin();
  placa.on("/",indice);
  placa.on("/encender",encender);
  placa.on("/apagar",apagar);
  placa.on("/estado",estado);
}

void indice(){                                    
  placa.sendHeader("Access-Control-Allow-Origin","*");
  placa.send(200, "text/html", "<!DOCTYPE html><html><head><meta charset=UTF-8><title>Taller IoT</title><style>body{font-family:'Montserrat',sans-serif;background-color:#cc4240;}.center {text-align: center;}.big {font-size: 100px;color: white;background-color: #9ec076;}.small {font-size: 30px;color: white;background-color: #415b8e;}</style></head><body><div class='center'><p class='big'>Taller IoT<br>Aula ATecA<br>M.B.Cossío<p class='small'>" + staticIP.toString() + "</p></div></body></html>");
}

void encender(){                                    
  placa.sendHeader("Access-Control-Allow-Origin","*");
  placa.send(200, "text/json", "{\"mensaje\":\"Encender\"}");
  digitalWrite(rele,LOW);
  status = 1;
}

void apagar(){                                    
  placa.sendHeader("Access-Control-Allow-Origin","*");
  placa.send(200, "text/json", "{\"mensaje\":\"Apagar\"}");
  digitalWrite(rele,HIGH);
  status = 0;
}

void estado(){                             
  placa.sendHeader("Access-Control-Allow-Origin","*");
  placa.send(200, "text/plain",String(status));
}
