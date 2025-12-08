# Práctica 1 — Visualizador de 7 Segmentos

**Universidad San Carlos de Guatemala**  
**Facultad de Ingeniería**  
**Ingeniería en Ciencias y Sistemas**

**Grupo:** G7  
**Repositorio:** ORGA_G7_DIC2025  
**Fecha:** Diciembre 2025

---

## Índice
1. Introducción
2. Objetivos
3. Alcance
4. Diseño del Sistema
   - Descripción general
   - Diagrama de bloques
5. Funciones booleanas por segmento
6. Mapas de Karnaugh
7. Implementación en Proteus
8. Implementación física (protoboard)
9. Pruebas y validación
10. Presupuesto
11. Aportes individuales
12. Conclusiones
13. Anexos

---

## 1. Introducción

Este documento presenta la implementación del **Visualizador de 7 Segmentos bidireccional (normal y espejo)** solicitado en la Práctica 1. El sistema muestra una palabra personalizada de cuatro caracteres (letras y/o números) tanto en su forma normal (display de cátodo común) como en espejo (display de ánodo común). La lógica se desarrolla mediante funciones booleanas simplificadas con mapas de Karnaugh y se implementa usando compuertas TTL y montaje en protoboard. También se incluye la simulación en Proteus en un solo archivo `.pdsprj`.


## 2. Objetivos

**Objetivo general**
- Diseñar e implementar un sistema funcional de visualización de 4 caracteres mediante displays de 7 segmentos, con visualización normal y espejo.

**Objetivos específicos**
- Derivar y simplificar las funciones booleanas para cada segmento (a–g).
- Implementar los términos mínimos para display de cátodo común y términos máximos para display de ánodo común.
- Simular el circuito completo en Proteus (archivo `.pdsprj`).
- Montar la lógica en protoboard empleando compuertas TTL 74xx y validar físicamente el funcionamiento.


## 3. Alcance

- Sistema completo con 4 caracteres a mostrar.
- Display frontal (cátodo común) con términos mínimos.
- Display trasero (ánodo común) en espejo con términos máximos.
- Al menos 3 funciones booleanas implementadas con transistores en PCB (archivo en /pcb).
- Simulación en un único archivo `.pdsprj`.
- Documentación técnica en Markdown, fotografías, presupuesto y video explicativo.


## 4. Diseño del Sistema

### Descripción general
El sistema consta de:
- **Entradas**: 4 líneas binarias que representan el carácter a mostrar (o un decodificador que traduzca un código a segmentos).
- **Lógica**: Módulo lógico que genera las señales para los 7 segmentos (a–g) según la combinación de entradas.
- **Displays**: 1 display de cátodo común (frontal) y 1 display de ánodo común (trasero) para el efecto espejo.

### Diagrama de bloques
_(Incluir aquí el diagrama de bloques generado en la carpeta `/documentacion/diagramas/`)_


## 5. Funciones booleanas por segmento

> **Nota:** A continuación se colocan las tablas de verdad y las expresiones (ejemplos). Reemplazar con las funciones finales simplificadas mediante mapas de Karnaugh.

### Segmento a
- Tabla de verdad: (incluir tabla)
- Expresión original: `a = ...`
- Expresión simplificada (términos mínimos - cátodo común): `a = ...`
- Expresión en términos máximos (ánodo común - espejo): `a' = ...`

### Segmento b
- Tabla de verdad: (incluir tabla)
- Expresión simplificada: `b = ...`

*(Repetir para c, d, e, f, g)*


## 6. Mapas de Karnaugh

Incluir 7 mapas de Karnaugh (uno por segmento) en la carpeta `./documentacion/imagenes/`. Cada mapa debe mostrar la agrupación usada para llegar a la expresión mínima.


## 7. Implementación en Proteus

- Archivo: `/simulacion/Practica1_G7.pdsprj` (consolidado, sin divisiones por módulos).
- Componentes principales: ICs 74xx (74LS08, 74LS32, 74LS04, etc.), resistencias y displays.
- Notas de simulación: indicar pruebas realizadas y resultados.


## 8. Implementación física (protoboard)

- Listado de componentes usado en protoboard.
- Diagramas y fotografías del montaje en `/fotos_montaje/`.
- Especificaciones de alimentación: 5 V DC para tecnología TTL; conexión Vcc y GND claramente identificada.


## 9. Pruebas y validación

- Procedimiento de pruebas: descripción paso a paso de cómo verificar que cada segmento enciende correctamente.
- Resultados: tabla con casos de prueba y observaciones.


## 10. Presupuesto

| Ítem | Cantidad | Precio unitario | Total |
|---|---:|---:|---:|
| Resistencias 220 Ω | 20 | Q0.50 | Q10.00 |
| IC 74LS08 | 2 | Q10.00 | Q20.00 |
| Displays 7-seg | 2 | Q15.00 | Q30.00 |
| Protoboard | 1 | Q35.00 | Q35.00 |
| Cables y jumpers | 1 | Q10.00 | Q10.00 |
| **Total estimado** |  |  | **Q105.00** |

_(Reemplazar precios por los reales y añadir más componentes si aplica)_


## 11. Aportes individuales

- **Cristofer Eduardo Nova Aguirre**: Diseño del PCB, implementación en protoboard y fotografías.
- **Integrante 2**: Mapas de Karnaugh y simplificación de funciones.
- **Integrante 3**: Simulación en Proteus y archivo `.pdsprj`.
- **Integrante 4**: Documentación, prespuesto y montaje del video.


## 12. Conclusiones

Breve resumen de los resultados obtenidos, dificultades encontradas y lecciones aprendidas.


## 13. Anexos

- `/simulacion/Practica1_G7.pdsprj`  
- `/documentacion/imagenes/`  
- `/fotos_montaje/`  
- `/video/enlace_video.txt`


---

**Instrucciones finales:**
- Completa las expresiones booleanas y mapas de Karnaugh con tus resultados reales.
- Reemplaza los precios del presupuesto por los comprobados.
- Agrega las fotos, diagramas y el archivo `.pdsprj` en sus carpetas correspondientes antes de subir al repositorio.


> Si quieres, puedo ahora:
> - Generar el `informe.md` completo con funciones booleanas y mapas de Karnaugh a partir de las tablas de verdad que me des, o
> - Exportar este README a un archivo `.md` descargable listo para subir.

