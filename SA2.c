#include <DHTesp.h> 
#include "WiFi.h"
#include "HTTPClient.h"

const char* ssid = "Wokwi-GUEST";
const char* password = "";

#define LEDPIN1 12
#define LEDPIN2 14


#define DHT_PIN 15 // Definindo pino de dados do sensor
float temperatura=0;
float humidade=0;

DHTesp dhtSensor; // Definindo o objeto do sensor

void setup() {

  Serial.begin(115200);
  pinMode(LEDPIN1, OUTPUT);
  pinMode(LEDPIN2, OUTPUT);
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);

  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Conectado...");

}

void loop() {

  HTTPClient http;

  String url = "https://api.thingspeak.com/update?api_key=PV1I1R52BY2A9S8R&field1=";

  TempAndHumidity data= dhtSensor.getTempAndHumidity();

  temperatura = data.temperature;
  humidade = data.humidity;

  url = url + temperatura + "&field2="+ humidade;

  if (temperatura>=35){ 
    digitalWrite(LEDPIN1, HIGH); 
  } else {
    digitalWrite(LEDPIN1, LOW);
  }

  if (humidade>=70){ 
    digitalWrite(LEDPIN2, HIGH); 
  } else {
    digitalWrite(LEDPIN2, LOW);
  }

  printf("Temperatura: %.1f°C   Humidade: %.1f%% \n", temperatura, humidade);  
  printf("+++++++++++++++++++++++++++++++++++++++\n");  


  http.begin(url);
  int httpCode = http.GET();
  Serial.println(httpCode);
  if(httpCode >= 200 && httpCode <= 299){
    String payload = http.getString();
    Serial.println(payload);
  } else{
    Serial.println("Problemas ao conectar API.");
  }


  delay;(1500); // espera por segundos
    
  
}
