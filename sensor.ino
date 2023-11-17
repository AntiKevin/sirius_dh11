#include <DHT.h>

#define DHTPIN 2 // O pino ao qual o DHT11 está conectado
#define DHTTYPE DHT11 // Tipo do sensor (DHT11)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000); // Aguarda alguns segundos entre as leituras

  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();

  if (isnan(umidade) || isnan(temperatura)) {
    Serial.println("Erro ao ler o sensor DHT11!");
    return;
  }

  Serial.print("Umidade: ");
  Serial.print(umidade);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");
}
