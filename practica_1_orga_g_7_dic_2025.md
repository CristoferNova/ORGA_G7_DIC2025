# Práctica 1 — Visualizador de 7 Segmentos

**Universidad San Carlos de Guatemala**
**Facultad de Ingeniería**
**Ingeniería en Ciencias y Sistemas**

**Curso:** Organización Computacional
**Práctica:** 1 — Visualizador de 7 Segmentos Bidireccional (Normal y Espejo)
**Grupo:** G7
**Fecha:** Diciembre 2025

---

## Carátula

**Integrantes:**

* Cristofer Eduardo Nova Aguirre
* (Agregar nombres adicionales del grupo)

**Catedrático:**

* (Nombre del catedrático)

**Repositorio GitHub:**
`ORGA_G7_DIC2025`

---

## 2. Introducción

Este informe presenta el diseño, simulación e implementación física de un sistema visualizador de **7 segmentos bidireccional**, el cual permite mostrar una palabra personalizada de cuatro caracteres tanto en modo **normal** como en **espejo**, utilizando dos tipos de display:

* **Cátodo común:** controlado mediante términos mínimos.
* **Ánodo común:** controlado mediante términos máximos invertidos.

El proyecto integra conceptos de lógica combinacional, mapas de Karnaugh, compuertas TTL, simulación electrónica con Proteus y montaje físico sobre protoboard.

---

## 3. Objetivos

### 3.1 Objetivo General

Implementar un sistema funcional capaz de visualizar cuatro caracteres mediante displays de 7 segmentos en orientación normal y espejo, utilizando compuertas lógicas simplificadas con mapas de Karnaugh.

### 3.2 Objetivos Específicos

* Derivar y simplificar funciones booleanas para cada segmento (a–g).
* Implementar términos mínimos en display cátodo común y términos máximos en display ánodo común.
* Realizar simulación completa en Proteus con un solo archivo `.pdsprj`.
* Montar el circuito en físico usando protoboard y compuertas TTL.
* Documentar el proceso con fotografías, diagramas, presupuesto y conclusiones.

---

## 4. Alcance

Este proyecto incluye:

* Visualización de 4 caracteres con lógica combinacional.
* Display frontal con cátodo común.
* Display trasero con ánodo común en modo espejo.
* Simulación completa en Proteus.
* Montaje físico del circuito utilizando ICs 74xx.
* Documentación completa en formato Markdown.
* Entrega de repositorio GitHub con todos los archivos.

---

## 5. Diseño del Sistema

### 5.1 Descripción General

El circuito recibe entradas digitales que corresponden a un carácter y genera señales que activan los segmentos del display. Se utiliza la tecnología TTL (74xx) para construir las compuertas lógicas.

### 5.2 Diagrama de Bloques

* Entradas binarias → Módulo lógico → Displays 7 segmentos.

> (Agregar imagen del diagrama en `/documentacion/diagramas/`)

---

## 6. Tablas de Verdad

Las tablas de verdad completas por segmento se encuentran documentadas en el archivo correspondiente.

Resumen de ejemplo:

| D   | C   | B   | A   | Segmento a |
| --- | --- | --- | --- | :--------: |
| 0   | 0   | 0   | 0   |      1     |
| 0   | 0   | 0   | 1   |      0     |
| ... | ... | ... | ... |     ...    |

---

## 7. Mapas de Karnaugh

Para cada segmento (a–g), se desarrolló un mapa de Karnaugh con los **minterms** correspondientes. Se usaron posiciones 10–15 como **don’t care** para optimización.

Los mapas (ASCII) se encuentran en el documento asociado y pueden visualizarse como imágenes.

> (Opcional: incluir PNGs en `/documentacion/imagenes/`)

---

## 8. Funciones Booleanas Simplificadas

### 8.1 Cátodo Común — SOP (Términos Mínimos)

```
a = A + C + (B·D) + (B'·D')
b = B' + (C·D) + (C'·D')
c = B + D + C'
d = A + (C·B') + (C·D') + (B'·D') + (B·D·C')
e = (C·D') + (B'·D')
f = A + (B·C') + (B·D') + (C'·D')
g = A + (B·C') + (C·B') + (C·D')
```

### 8.2 Ánodo Común — POS (Términos Máximos)

```
a = A' · C' · (B + D) · (B' + D')
b = B · (C + D) · (C' + D')
c = C · B' · D'
d = A' · (B + D) · (B + C') · (D + C') · (C + B' + D')
e = (B + D) · (D + C')
f = A' · (C + D) · (C + B') · (D + B')
g = A' · (B + C') · (C + B') · (D + C')
```

---

## 9. Simulación en Proteus

### 9.1 Archivo de Simulación

El archivo `.pdsprj` contiene todo el circuito consolidado.

Ruta sugerida en repositorio:

```
/simulacion/Practica1_G7.pdsprj
```

### 9.2 Resultados

* Los segmentos activan correctamente según las entradas.
* Los términos mínimos se validaron visualmente en Proteus.

---

## 10. Implementación Física

### 10.1 Montaje en Protoboard

* Se emplearon ICs TTL 74xx.
* Alimentación de **5 V DC**.
* Distribución ordenada de señales, Vcc y GND.

> (Agregar fotografías en `/fotos_montaje/`)

### 10.2 Validación

* Cada número se probó manualmente.
* El sistema enciende correctamente segmentos frontales y traseros.

---

## 11. Presupuesto

| Componente               | Cantidad | Precio Unitario |       Total |
| ------------------------ | -------: | --------------: | ----------: |
| Protoboard               |        1 |          Q35.00 |      Q35.00 |
| IC TTL 74xx              |        6 |          Q10.00 |      Q60.00 |
| Resistencias 220 Ω       |       20 |           Q0.50 |      Q10.00 |
| Displays 7 Seg.          |        2 |          Q15.00 |      Q30.00 |
| Cableado                 |        1 |          Q10.00 |      Q10.00 |
| **Costo Total Estimado** |          |                 | **Q145.00** |

---

## 12. Aportes Individuales

| Integrante     | Aporte                                 |
| -------------- | -------------------------------------- |
| Cristofer Nova | Diseño PCB, protoboard y documentación |
| Integrante 2   | Mapas Karnaugh y funciones booleanas   |
| Integrante 3   | Simulación en Proteus                  |
| Integrante 4   | Video explicativo y presupuesto        |

---

## 13. Conclusiones

* Se logró implementar exitosamente el sistema visualizador bidireccional.
* Los mapas de Karnaugh permitieron minimizar la cantidad de compuertas utilizadas.
* La simulación en Proteus se consolidó en un único archivo funcional.
* El montaje físico cumplió los requerimientos de activación de segmentos.

---

## 14. Anexos

* `/simulacion/Practica1_G7.pdsprj`
* `/documentacion/imagenes/`
* `/fotos_montaje/`
* `/video/enlace_video.txt`

---




