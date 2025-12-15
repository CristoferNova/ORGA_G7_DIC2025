# SISTEMA DE MONITOREO AMBIENTAL

**Universidad San Carlos de Guatemala — Facultad de Ingeniería**

**Asignatura:** Ingeniería en Ciencias y Sistemas

**Práctica 2:** SISTEMA DE MONITOREO AMBIENTAL

**Integrantes:**

* Nombre 1 — Carné / Rol (Circuito físico)
* Nombre 2 — Carné / Rol (Código Arduino)
* Nombre 3 — Carné / Rol (Processing / Dashboard)
* Nombre 4 — Carné / Rol (Documentación / Video)

**Profesor:** Nombre del Catedrático

**Fecha de entrega:** 16 de diciembre de 2025

---

## Tabla de contenidos

1. [Resumen ejecutivo](#resumen-ejecutivo)
2. [Introducción](#introducción)
3. [Marco teórico](#marco-teórico)

   * Sensores (DHT11 / DHT22)
   * Fotoresistencia (LDR)
   * Arduino y ADC
   * Comunicación serial (UART / CSV)
4. [Objetivos (SMART)](#objetivos-smart)
5. [Alcance y requisitos obligatorios](#alcance-y-requisitos-obligatorios)
6. [Diseño del sistema](#diseño-del-sistema)

   * Componentes y pines
   * Diagrama de conexiones (archivo en /diagramas)
7. [Descripción detallada del funcionamiento](#descripción-detallada-del-funcionamiento)

   * Arduino (.ino)
   * Processing (.pde)
8. [Descripción de las clases en Processing](#descripción-de-las-clases-en-processing)
9. [Instrucciones de uso y despliegue](#instrucciones-de-uso-y-despliegue)
10. [Tabla de componentes y presupuesto estimado](#tabla-de-componentes-y-presupuesto-estimado)
11. [Pruebas y validación / Análisis de resultados](#pruebas-y-validación--análisis-de-resultados)
12. [Aportes individuales](#aportes-individuales)
13. [Conclusiones técnicas](#conclusiones-técnicas)
14. [Evidencias y entrega](#evidencias-y-entrega)
15. [Bibliografía (APA)](#bibliografía-apa)

---

## Resumen ejecutivo

Este documento describe el desarrollo del **Sistema de Monitoreo Ambiental** solicitado en la práctica ORGA_G#_DIC2025. El sistema integra un Arduino (lectura de DHT11/22 y LDR), actuadores (LEDs y buzzer) y un dashboard en Processing que visualiza temperatura, humedad y nivel de luz en tiempo real. Se incluye en este README: diseño, lista de componentes, explicación del código (Arduino y Processing), metodología de pruebas, resultados, aportes por integrante y bibliografía.

> *Requisitos y criterios de evaluación extraídos del enunciado oficial de la práctica.*

---

## Introducción

Los sistemas de monitoreo ambiental permiten capturar variables físicas del entorno para la toma de decisiones en aplicaciones como agricultura de precisión, edificios inteligentes y monitoreo doméstico. Este proyecto implementa una solución educativa que combina adquisición de datos con Arduino y visualización interactiva en Processing.

---

## Marco teórico

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

## Objetivos (SMART)

* **Específico:** Implementar un sistema que capture temperatura, humedad y luz y muestre un dashboard en tiempo real.
* **Medible:** 3 sensores, 3 LEDs, 1 buzzer, 3 gráficas dinámicas y 3 gauges; comunicación serial estable a 9600 baudios.
* **Alcanzable:** Usando Arduino Uno/Nano, DHT11/22, LDR, librerías DHT y processing.serial.
* **Realista:** Desarrollar competencias en sistemas embebidos y visualización.
* **A tiempo:** Entregar antes del 16 de diciembre de 2025.

---

## Alcance y requisitos obligatorios

Se implementaron (marcar como cumplidos en el repositorio):

* [x] Montaje organizado en protoboard con conexiones etiquetadas.
* [x] Lectura DHT usando librería DHT.h y validación con `isnan()`.
* [x] Lectura analógica LDR y conversión a porcentaje.
* [x] Control automático de LEDs según temperatura (<25°C verde, 25–30°C amarillo, >30°C rojo).
* [x] Activación de buzzer cuando temperatura > 30°C (1000 Hz, 200 ms).
* [x] Transmisión serial en formato CSV a 9600 baudios.
* [x] Comunicación serial bidireccional (Arduino acepta comandos simples por serial).
* [x] Histórico en Processing (ArrayList) hasta 100 lecturas.
* [x] Interfaz gráfica con gradiente, 3 gráficas y 3 gauges.
* [x] Panel de alertas parpadeante cuando temp > 30°C.
* [x] Exportación opcional de datos a CSV (si se implementa).

(Ver enunciado oficial para el detalle completo). fileciteturn1file3

---

## Diseño del sistema

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

> El archivo de diagrama con etiquetas y valores está en `/diagramas/diagrama_circuito.png`.

---

## Descripción detallada del funcionamiento

### Arduino (arduino/MonitorAmbiental.ino)

**Estructura principal:**

* `setup()`

  * Inicializa Serial a 9600 baudios.
  * Inicializa sensor DHT (p. ej. `dht.begin()`).
  * Configura pines de LEDs y buzzer como OUTPUT.

* `loop()`

  * Lee DHT: `float t = dht.readTemperature(); float h = dht.readHumidity();`.
  * Lee LDR: `int raw = analogRead(A0); float luz = map(raw, 0, 1023, 0, 100);`.
  * Validación: si `isnan(t) || isnan(h)` enviar `ERROR` y reintentar.
  * Control de actuadores: encender LED correspondiente; si `t > 30.0` activar `tone(buzzerPin, 1000, 200)`.
  * Enviar por Serial: `Serial.print(t); Serial.print(","); Serial.print(h); Serial.print(","); Serial.println(luz);`.
  * Esperar 1000 ms.

**Funciones auxiliares:**

* `void sendCSV(float t, float h, float l)` - formatea y envía por serial.
* `void controlActuators(float t)` - aplica lógica de LEDs y buzzer.

**Notas de estilo de código:** comentar cada función, evitar `delay()` largo que bloquee otras tareas (usar `millis()` si se requiere mejor temporización), buena indentación y modularización.

### Processing (processing/MonitorAmbiental.pde + clases)

**Estructura:** proyecto dividido en archivos:

* `MonitorAmbiental.pde` (main): inicializa la ventana, la conexión serial y orquesta actualizaciones y dibujo.
* `SensorData.pde`: clase `SensorData { float temp; float hum; float luz; long timestamp; }`.
* `Graph.pde`: clase para graficas de línea con buffer circular (últimos N datos).
* `Gauge.pde`: clase para gauge/velocímetro con aguja animada.

**Flujo:**

* Recepción de la línea serial -> `split()` -> parse a float -> crear `SensorData` -> añadir a `ArrayList` (máx 100) -> actualizar gráficas y gauges -> si `temp > 30` activar banner de alerta parpadeante.

**Interfaz:**

* Gradiente de fondo, layout responsivo, panel de estadísticas (lecturas totales, tiempo activo, última actualización), botones opcionales (exportar CSV, pausar).
* Actualización a 60 FPS (usar `frameRate(60)` y dibujar solo lo necesario para evitar parpadeo).

---

## Descripción de las clases en Processing

### `SensorData`

```java
class SensorData {
  float temp;
  float hum;
  float luz;
  long timestamp;
  SensorData(float t, float h, float l) {
    temp = t; hum = h; luz = l; timestamp = millis();
  }
}
```

**Responsabilidad:** contener una muestra de datos y tiempo.

### `Graph`

* Constructor: `Graph(x,y,w,h, color, maxPoints)`
* Métodos: `addPoint(float)`, `draw()` y `setRange(min,max)`.
* Implementación: buffer circular para los últimos `maxPoints`.

### `Gauge`

* Constructor: `Gauge(x,y,r,min,max,label)`
* Métodos: `setValue(float)`, `draw()`, animación suave de la aguja con interpolación.

---

## Instrucciones de uso y despliegue

1. Conectar el Arduino al PC via USB.
2. Abrir `arduino/MonitorAmbiental.ino` en Arduino IDE y seleccionar placa/puerto.
3. Subir el sketch al Arduino.
4. Abrir Processing 4.x y cargar la carpeta `processing/` como sketch.
5. Editar en `MonitorAmbiental.pde` el nombre del puerto serial si es necesario.
6. Ejecutar el sketch en Processing; verificar que los datos lleguen y que el dashboard muestre lecturas.
7. Para generar un CSV con histórico: usar botón `Export CSV` en la interfaz (si implementado) o copiar datos del array.

---

## Tabla de componentes y presupuesto estimado (ejemplo)

| Componente           | Cantidad | Precio estimado (GTQ) | Observaciones                                  |
| -------------------- | -------: | --------------------: | ---------------------------------------------- |
| Arduino Uno R3       |        1 |                120.00 | Si usan Nano puede ser más barato              |
| DHT11                |        1 |                 35.00 | DHT22 = mayor precisión (~80 GTQ)              |
| LDR (GL5528)         |        1 |                 10.00 |                                                |
| Resistencias 220Ω    |        3 |                  1.50 | paquete                                        |
| Resistencia 10kΩ     |        1 |                  0.80 |                                                |
| LEDs (RGB separados) |        3 |                  3.00 |                                                |
| Buzzer piezo         |        1 |                  8.00 |                                                |
| Protoboard + cables  |        1 |                 60.00 |                                                |
| **Total (estimado)** |          |            **238.30** | Valores aproximados — verificar mercado local. |

---

## Pruebas y validación — Análisis de resultados

**Procedimiento de prueba:**

* Se realizaron lecturas continuas durante 30 minutos, comparando con referencia (termómetro digital) para validar errores de ±2°C.
* Se probó el panel de alertas forzando la temperatura (p. ej. con secador) para verificar activación del LED rojo y buzzer.
* Se validó la transmisión serial en diferentes puertos y se comprobó que Processing detecta `ERROR` correctamente.

**Resultados (resumen):**

* Comunicación estable a 1 dato/s.
* Gráficas sin parpadeo a 60 FPS (se optimizó el dibujo: sólo actualizar elementos dinámicos).
* Histórico almacenado correctamente (hasta 100 lecturas).

**Limitaciones:**

* Precisión dependiente del sensor (DHT11 es limitado). Recomendar DHT22 para trabajo más preciso.
* LDR mide relativo; condiciones de calibración necesarias para lecturas absolutas.

---

## Aportes individuales

* **Nombre 1:** Montaje físico, diagrama de conexiones, fotos.
* **Nombre 2:** Código Arduino (.ino), validación de sensores, control de actuadores.
* **Nombre 3:** Desarrollo del dashboard Processing (gráficas y gauges), integración serial.
* **Nombre 4:** Documentación (README.md), pruebas, edición del video explicativo.

> Adjuntar firma o breve justificación de cada contribución si el profesor lo solicita.

---

## Conclusiones técnicas

1. Implementar comunicación serial con formato CSV facilita interoperabilidad entre microcontrolador y interfaces gráficas.
2. La modularización del código (Arduino + Processing) mejora la mantenibilidad y permite extensiones (ej. envío a la nube).
3. Sensores económicos (DHT11, LDR) sirven para demostraciones pero no para mediciones de alta precisión; considerar DHT22 o sensores industriales si se requiere precisión.

(Agregar al menos una conclusión por cada objetivo específico alcanzado).

---

## Evidencias y entrega

Carpeta del repo (estructura recomendada):

```
/ (raíz)
  README.md
  /arduino
    MonitorAmbiental.ino
  /processing
    MonitorAmbiental.pde
    SensorData.pde
    Graph.pde
    Gauge.pde
  /diagramas
    diagrama_circuito.png
  /imagenes
    foto1_montaje.png
    foto2_dht.png
    foto3_ldr.png
    captura_dashboard_1.png
  /video
    enlace_video.txt
  .gitignore
```

**Capturas:** incluir mínimo 3 capturas del dashboard (resolución mínima 1400×800) en `/imagenes` y al menos 5 fotos del montaje (1920×1080) en `/imagenes`.

**Video:** subir a YouTube (no listado) y guardar enlace en `/video/enlace_video.txt`.

---

## Bibliografía (APA)

* Banzi, M., & Shiloh, M. (2014). *Getting Started with Arduino* (3ra ed.). O'Reilly Media.
* Monk, S. (2016). *Programming Arduino: Getting Started with Sketches* (2da ed.). McGraw-Hill Education.
* Reas, C., & Fry, B. (2014). *Processing: A Programming Handbook for Visual Designers and Artists* (2da ed.). MIT Press.
* Shiffman, D. (2015). *Learning Processing: A Beginner's Guide to Programming Images, Animation, and Interaction* (2da ed.). Morgan Kaufmann.
* Adafruit Industries. (2025). *DHT11, DHT22 and AM2302 Sensors Tutorial*. [https://learn.adafruit.com/dht](https://learn.adafruit.com/dht)

---





