# SISTEMA DE MONITOREO AMBIENTAL

**Universidad San Carlos de Guatemala — Facultad de Ingeniería**

**Asignatura:** Ingeniería en Ciencias y Sistemas

**Práctica 2:** SISTEMA DE MONITOREO AMBIENTAL

**Integrantes:**

* Cristofer Eduardo Nova Aguirre Carne: 2842042262204
* Cristopher Alberto León España Carne: 2471454672001
* Saúl Andrés Monroy Marroquín Carne: 2472832662001
* Jose Gustavo Alvarez Sequen Carne: 2472540102001

**Profesor:** 
* Dilan Conaher Suy Miranda

**Fecha:** 16 de diciembre de 2025

---
## 1. Introducción
El presente proyecto corresponde a la **Práctica 2**, cuyo objetivo es el diseño e implementación de un sistema de monitoreo ambiental utilizando la plataforma Arduino y el entorno gráfico Processing. El sistema es capaz de medir variables ambientales como temperatura, humedad y nivel de iluminación, permitiendo su visualización en tiempo real mediante un dashboard interactivo.

Este tipo de sistemas es ampliamente utilizado en aplicaciones académicas e industriales, ya que facilita la adquisición, análisis y visualización de datos ambientales de manera eficiente.

---

## 2.Marco teórico

### Sensor DHT11 / DHT22

* **Qué mide:** temperatura (°C) y humedad relativa (%).
* **Protocolos:** comunicación serial digital en línea única (librería DHT.h de Adafruit).
* **Precisión / rango:** DHT11 (~0–50°C, ±2°C, 20–90% HR), DHT22 ofrece mayor precisión.
* **Notas de uso:** evitar lecturas demasiado frecuentes (usar >= 1 s entre lecturas), validar con `isnan()`.

### Fotoresistencia (LDR)

* **Qué mide:** variación de resistencia en función de la intensidad de luz.
* **Montaje:** usar un divisor de tensión con una resistencia fija (10 kΩ recomendado) y LDR conectada a entrada analógica A0.
* **Conversión:** ADC 10 bits (0–1023). Normalizar a 0–100% con `map()` o cálculo float.

### Arduino y ADC

* Microcontrolador: ATmega328P (Arduino Uno/Nano).
* ADC: 10 bits, referencia 5V por defecto.
* Pines de salida digitales para LEDs y buzzer; usar resistencias limitadoras para LEDs.

### Comunicación serial (UART / CSV)

* Configuración: `Serial.begin(9600)`.
* Formato: `temperatura,humedad,luz\n` (ej.: `24.5,65.2,75`).
* Error: Arduino enviará la cadena `ERROR` si falla la lectura; Processing debe ignorarla.

---

## 3. Objetivos

### 3.1 Objetivo general
1. Diseñar e implementar un sistema de monitoreo ambiental que permita la adquisición y visualización en tiempo real de temperatura, humedad y luz ambiental utilizando Arduino y Processing.

### 3.2 Objetivos específicos
1. Implementar la lectura correcta del sensor de temperatura y humedad (DHT).
2. Medir el nivel de iluminación mediante una fotoresistencia (LDR).
3. Enviar los datos obtenidos a través de comunicación serial en formato CSV.
4. Visualizar los datos en un dashboard gráfico desarrollado en Processing.
5. Implementar alertas visuales y sonoras cuando la temperatura supere un umbral definido.
6. Integrar correctamente hardware y software en un sistema funcional.

---

## 4. Desarrollo del sistema
### Lista de componentes (físicos)

* Arduino Uno R3 o Nano
* Sensor DHT11 o DHT22
* LDR (GL5528 recomendado)
* 3 × LEDs (verde, amarillo, rojo) + resistencias 220 Ω
* Buzzer piezoeléctrico (activo o pasivo)
* Protoboard y cables jumper
* Resistencia fija 10 kΩ (divisor LDR)
* Cable USB A-B

### Pines utilizados (configuración propuesta)

* DHT data -> pin digital 2
* LDR -> A0 (con divisor 10k)
* LED Verde -> D8
* LED Amarillo -> D9
* LED Rojo -> D10
* Buzzer -> D11

### 4.1 Montaje físico
El montaje físico del sistema se realizó utilizando una protoboard, un Arduino, sensores y actuadores. Se conectó el sensor DHT para medir temperatura y humedad, una LDR para la medición de luz, LEDs indicadores y un buzzer para alertas.

**Evidencias del montaje físico:**

```
Practica2/MontajeFisico_Fotos
```
---

### 4.2 Simulación en TinkerCAD
Antes del montaje físico, el circuito fue simulado en TinkerCAD con el fin de validar las conexiones y el funcionamiento general del sistema.

**Simulación del circuito:**

```
Practica2/Simulacion_TinkerCAD
```
---

### 4.3 Desarrollo del código en Arduino
El código desarrollado en Arduino se encarga de:
- Leer los sensores DHT y LDR.
- Procesar los valores obtenidos.
- Controlar los LEDs y el buzzer según la temperatura.
- Enviar los datos al puerto serial en formato CSV.

El archivo correspondiente se encuentra en:

```
Practica2/Practica2_G7_ArduinoIDE
```

---

### 4.4 Dashboard en Processing
Se desarrolló un dashboard en Processing que recibe los datos enviados por Arduino mediante el puerto serial y los presenta gráficamente en tiempo real, permitiendo una interpretación clara de las variables ambientales.

**Capturas del dashboard y Processing:**

```
Practica2/ProcessingProyecto_Fotos
```

---

## 5. Resultados obtenidos
El sistema funcionó correctamente durante las pruebas realizadas. Los datos de temperatura, humedad y luz fueron capturados de manera estable y visualizados en el dashboard sin pérdidas de información. Las alertas visuales y sonoras se activaron correctamente cuando la temperatura superó el umbral establecido.

---

## 6. Evidencias
Todas las evidencias del proyecto, incluyendo código fuente, imágenes del montaje físico, simulación en TinkerCAD y capturas del dashboard, se encuentran organizadas dentro del repositorio del proyecto.

---
---

## 7.Tabla de componentes y presupuesto estimado:

| Componente           | Cantidad | Precio estimado (GTQ) | 
| -------------------- | -------: | --------------------: | 
| Arduino mega         |        1 |                250.00 |              
| DHT11                |        1 |                 30.00 |              
| LDR (GL5528)         |        1 |                 10.00 |                                                
| Resistencias 220Ω    |        3 |                  1.50 |                                         
| Resistencia 10kΩ     |        1 |                  0.80 |                                                
| LEDs (RGB separados) |        3 |                  3.00 |                                                
| Buzzer piezo         |        1 |                  8.00 |                                                
| Protoboard + cable UTP|       1 |                 60.00 |                                                
| **Total (estimado)** |          |            **363.30** |                                               

---

## 8. Aportes Individuales

| Integrante     | Aporte                                 |
| -------------- | -------------------------------------- |
| Cristofer Eduardo Nova Aguirre | Simulacion en TinkerCAD y documentación |
| Cristopher Alberto LeónEspaña   | Montaje Fisico y Compra de Componentes  |
| Saúl Andrés Monroy Marroquín   | Codigo Arduino(.ino) y Codigo en Processing|
| Jose Gustavo Alvarez Sequen   | Video explicativo y presupuesto|

---

---

## 9. Conclusiones
1. Se logró implementar exitosamente un sistema de monitoreo ambiental funcional utilizando Arduino y Processing.
2. La comunicación serial permitió una transferencia eficiente y confiable de datos entre Arduino y Processing.
3. El uso de Processing facilitó la visualización clara e intuitiva de los datos en tiempo real.
4. El proyecto permitió reforzar conocimientos de electrónica, programación y adquisición de datos.
5. Arduino demostró ser una plataforma adecuada para el desarrollo de prototipos educativos.

---

## 10.Bibliografía (APA)

* Banzi, M., & Shiloh, M. (2014). *Getting Started with Arduino* (3ra ed.). O'Reilly Media.
* Monk, S. (2016). *Programming Arduino: Getting Started with Sketches* (2da ed.). McGraw-Hill Education.
* Reas, C., & Fry, B. (2014). *Processing: A Programming Handbook for Visual Designers and Artists* (2da ed.). MIT Press.
* Shiffman, D. (2015). *Learning Processing: A Beginner's Guide to Programming Images, Animation, and Interaction* (2da ed.). Morgan Kaufmann.
* Adafruit Industries. (2025). *DHT11, DHT22 and AM2302 Sensors Tutorial*. [https://learn.adafruit.com/dht](https://learn.adafruit.com/dht)

---





