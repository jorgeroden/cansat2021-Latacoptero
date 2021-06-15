//CANSAT 2021
//Equipo: Latacóptero
//IES Andrés de Vandelvira

#include "libSD.h"
#include "libPressTemp.h"
#include "libUltraV.h"
#include<SoftwareSerial.h>

long flag = millis();
long flag2 = millis();
boolean ultimoEnvio = false;
boolean envio = false;
boolean ultimoSalvaSD = false;
boolean salvaSD = false;
SoftwareSerial radio(8,9); //9-Rx, 8-Tx
String datos;

void setup()
{
  Serial.begin(9600);
  initPressTemp();
  initSD();
  initUV();
  radio.begin(9600);
}

void loop()
{

  if (millis() - flag > 1000)//Se envia cada 1000ms
  {
    envio  = !envio;
    flag = millis();
  }
  if (millis() - flag2 > 200)//se guarda en SD cada 200 ms
  {
    salvaSD = ! salvaSD;
    flag2 = millis();
  }

  // Datos a SD
  if (ultimoSalvaSD != salvaSD) {

    datos = getPressTemp() + "," + getUV();// Añadir el resto de datos
    writeSD(datos);//funcion para guardar todos los datos en la SD
    Serial.println("grabado en SD.");
    Serial.println(datos);
    ultimoSalvaSD = salvaSD;
  }

  if (ultimoEnvio != envio)
  {
    // Envio por radio de datos de mision primaria

    ultimoEnvio = envio;
    Serial.println("Enviando datos ...");
    radio.println(datos); // Comprobar
  
  
  }

    
}
