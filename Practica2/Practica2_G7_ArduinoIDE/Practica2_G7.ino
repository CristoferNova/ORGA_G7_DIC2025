// ----------------------------------------------------------
// SISTEMA DE MONITOREO AMBIENTAL (Versión ARDUINO FÍSICO)
// Sensor DHT11: temperatura y humedad (pin D2)
// Sensor LDR: nivel de luz (A0)
// LEDs y buzzer según temperatura
// Envío CSV: temp, humedad, luz
// ----------------------------------------------------------

#include <DHT.h>

// -------------------
// CONFIGURACIÓN PINS
// -------------------
#define DHTPIN 2        // Pin de datos del DHT11
#define DHTTYPE DHT11   // Tipo de sensor
#define LDRPIN A0

#define LED_GREEN 8
#define LED_YELLOW 9
#define LED_RED 10
#define BUZZER 11

DHT dht(DHTPIN, DHTTYPE);

// ----------------------------------------------------------
// INICIALIZACIÓN PINES
// ----------------------------------------------------------
void inicializarPines() {
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);
  noTone(BUZZER);
}

// ----------------------------------------------------------
// LECTURA DEL SENSOR DHT11
// ----------------------------------------------------------
float leerTemperatura() {
  return dht.readTemperature(); // °C
}

float leerHumedad() {
  return dht.readHumidity();    // %RH
}

// ----------------------------------------------------------
// LECTURA DEL SENSOR LDR (0-100%)
// ----------------------------------------------------------
float leerLuz() {
  int raw = analogRead(LDRPIN);
  return map(raw, 0, 1023, 0, 100);
}

// ----------------------------------------------------------
// CONTROL DE LEDs Y BUZZER SEGÚN TEMPERATURA
// ----------------------------------------------------------
void controlarActuadores(float temp) {

  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);
  noTone(BUZZER);

  if (temp < 25) {
    digitalWrite(LED_GREEN, HIGH);
  }
  else if (temp >= 25 && temp <= 30) {
    digitalWrite(LED_YELLOW, HIGH);
  }
  else if (temp > 30) {
    digitalWrite(LED_RED, HIGH);
    tone(BUZZER, 1000, 200);
  }
}

// ----------------------------------------------------------
// ENVÍO DE DATOS EN FORMATO CSV
// temp, humedad, luz
// ----------------------------------------------------------
void enviarCSV(float t, float h, float luz) {
  Serial.print(t);
  Serial.print(",");
  Serial.print(h);
  Serial.print(",");
  Serial.println(luz);
}

// ----------------------------------------------------------
// SETUP
// ----------------------------------------------------------
void setup() {
  Serial.begin(9600);
  dht.begin();
  inicializarPines();
}

// ----------------------------------------------------------
// LOOP PRINCIPAL
// ----------------------------------------------------------
void loop() {

  float temp = leerTemperatura();
  float hum = leerHumedad();
  float luz = leerLuz();

  // Validar lectura del DHT
  if (isnan(temp) || isnan(hum)) {
    Serial.println("ERROR");
    delay(1000);
    return;
  }

  enviarCSV(temp, hum, luz);
  controlarActuadores(temp);

  delay(1000);
}
