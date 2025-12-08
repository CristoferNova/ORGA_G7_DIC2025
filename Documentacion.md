# Práctica 1 — Visualizador de 7 Segmentos

**Universidad San Carlos de Guatemala**
**Facultad de Ingeniería**
**Ingeniería en Ciencias y Sistemas**

**Curso:** Organización Computacional
**Práctica:** 1 — Visualizador de 7 Segmentos Bidireccional (Normal y Espejo)
**Grupo:** G7
**Fecha:** Diciembre 2025

---

## 1. Carátula

**Integrantes:**

* Cristofer Eduardo Nova Aguirre Carne:2842042262204
* Cristopher Alberto León España Carne:2471454672001
* Saúl Andrés Monroy Marroquín Carne:2472832662001
* Jose Gustavo Alvarez Sequen Carne:2472540102001

**Catedrático:**

* Dilan Conaher Suy Miranda

**Repositorio GitHub:**
`ORGA_G7_DIC2025`

---

## 2. Introducción

Este informe presenta el diseño, simulación e implementación física de un sistema visualizador de **7 segmentos bidireccional**, el cual permite mostrar una palabra personalizada de cuatro caracteres tanto en modo **normal** como en **espejo**.

Se utilizan dos tipos de display:

* **Cátodo común:** controlado mediante términos mínimos.
* **Ánodo común:** controlado mediante términos máximos.

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

El circuito recibe entradas digitales que corresponden a un carácter y genera señales que activan los segmentos del display. Se utiliza tecnología TTL (74xx) para construir las compuertas lógicas.

---

## 6. Tablas de Verdad, Mapas de Karnaugh y Expresiones 

Este documento contiene:
- Tablas de verdad de segmentos `a–g`
- Mapas de Karnaugh (ASCII)
- Expresiones simplificadas (SOP y POS)

---
## Convenciones utilizadas

Entradas:
```
W = bit menos significativo (LSB)
X = siguiente bit
Y = siguiente bit
Z = bit más significativo (MSB)
```

Índice de minterm:
```
index = W + 2X + 4Y + 8Z
```

Formato decimal para BCD:
```
p = 0000
a = 0001
c = 0010
a = 1001
```


---
# 6.1) Tablas de verdad Modo Normal

| DECIMAL | LETRA | w | x | y | z |
|---:|:---:|:---:|:---:|:---:|:---:|
| 1  | p | 0 | 0 | 0 | 0 |
| 2  | a | 0 | 0 | 0 | 1 |
| 3  | c | 0 | 0 | 1 | 0 |
| 4  | a | 0 | 0 | 1 | 1 |
| 5  |   | 0 | 1 | 0 | 0 |
| 6  |   | 0 | 1 | 0 | 1 |
| 7  |   | 0 | 1 | 1 | 0 |
| 8  |   | 0 | 1 | 1 | 1 |
| 9  |   | 1 | 0 | 0 | 0 |
| 10 |   | 1 | 0 | 0 | 1 |
| 11 |   | 1 | 0 | 1 | 0 |
| 12 |   | 1 | 0 | 1 | 1 |
| 13 |   | 1 | 1 | 0 | 0 |
| 14 |   | 1 | 1 | 0 | 1 |
| 15 |   | 1 | 1 | 1 | 0 |
| 16 |   | 1 | 1 | 1 | 1 |

---

| a | b | c | d | e | f | g | . |
|---|---|---|---|---|---|---|---|
| 1 | 1 | 0 | 0 | 1 | 1 | 1 | 0 |
| 1 | 1 | 1 | 1 | 1 | 0 | 1 | 0 |
| 1 | 0 | 0 | 1 | 1 | 1 | 0 | 0 |
| 1 | 1 | 1 | 1 | 1 | 0 | 1 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |



---
# 6.2) Mapas de Karnaugh y Expresiones Modo Normal
```
Seg a		YZ			
		00	01	11	10
WX	00	1	1	1	1
	01	0	0	0	0
	11	0	0	0	0
	10	0	0	0	0
					
	a= w'x'				
```					
```					
Seg b		YZ			
		00	01	11	10
WX	00	1	1	1	0
	01	0	0	0	0
	11	0	0	0	0
	10	0	0	0	0
					
	b= w'x'y' + w'x'z			b= w'x'(y'+z)	
```				
```				
Seg c		YZ			
		00	01	11	10
WX	00	0	1	1	0
	01	0	0	0	0
	11	0	0	0	0
	10	0	0	0	0
					
	c= w'x'z				
```					
```					
Seg d		YZ			
		00	01	11	10
WX	00	0	1	1	1
	01	0	0	0	0
	11	0	0	0	0
	10	0	0	0	0
					
	d=  w'x'z + w'x'y		d= w'x'(y+z)		
```					
```					
Seg e		YZ			
		00	01	11	10
WX	00	1	1	1	1
	01	0	0	0	0
	11	0	0	0	0
	10	0	0	0	0
					
	e=w'x' 	mismo que el a			
```					
```					
Seg f		YZ			
		00	01	11	10
WX	00	1	0	0	1
	01	0	0	0	0
	11	0	0	0	0
	10	0	0	0	0
					
	f=w'x'z' 				
```					
```					
Seg g		YZ			
		00	01	11	10
WX	00	1	1	1	0
	01	0	0	0	0
	11	0	0	0	0
	10	0	0	0	0
					
	g= w'x'y' + w'x'z		g=w'x'(y'+z)		mismo que el b

```


---
# 6.3) Tablas de verdad Modo espejo

---
| DECIMAL | LETRA | w | x | y | z |
|---:|:---:|:---:|:---:|:---:|:---:|
| 1  | p | 0 | 0 | 0 | 0 |
| 2  | a | 0 | 0 | 0 | 1 |
| 3  | c | 0 | 0 | 1 | 0 |
| 4  | a | 0 | 0 | 1 | 1 |
| 5  |   | 0 | 1 | 0 | 0 |
| 6  |   | 0 | 1 | 0 | 1 |
| 7  |   | 0 | 1 | 1 | 0 |
| 8  |   | 0 | 1 | 1 | 1 |
| 9  |   | 1 | 0 | 0 | 0 |
| 10 |   | 1 | 0 | 0 | 1 |
| 11 |   | 1 | 0 | 1 | 0 |
| 12 |   | 1 | 0 | 1 | 1 |
| 13 |   | 1 | 1 | 0 | 0 |
| 14 |   | 1 | 1 | 0 | 1 |
| 15 |   | 1 | 1 | 1 | 0 |
| 16 |   | 1 | 1 | 1 | 1 |
---
| a | b | c | d | e | f | g | . |
|---:|---:|---:|---:|---:|---:|---:|---:|
| 0 | 0 | 0 | 1 | 1 | 0 | 0 | 1 |
| 0 | 1 | 0 | 0 | 0 | 0 | 0 | 1 |
| 0 | 0 | 0 | 0 | 1 | 1 | 1 | 1 |
| 0 | 1 | 0 | 0 | 0 | 0 | 0 | 1 |
| 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
| 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
| 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
| 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
| 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
| 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
| 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
| 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
| 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
| 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
| 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
| 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
---
# 6.4) Mapas de Karnaugh y Expresiones Modo Espejo
```
Seg a		YZ				
		00	01	11	10	
WX	00	0	0	0	0	
	01	1	1	1	1	
	11	1	1	1	1	
	10	1	1	1	1	
						
	a= (w+x)					
```						
```						
Seg b		YZ				
		00	01	11	10	
WX	00	0	1	1	0	
	01	1	1	1	1	
	11	1	1	1	1	
	10	1	1	1	1	
						
	b= (w+x+z)					
```						
```						
Seg c		YZ				
		00	01	11	10	
WX	00	0	0	0	0	
	01	1	1	1	1	
	11	1	1	1	1	
	10	1	1	1	1	
						
	c= (w + x)	igual que el a				
```						
```						
Seg d		YZ				
		00	01	11	10	
WX	00	1	0	0	0	
	01	1	1	1	1	
	11	1	1	1	1	
	10	1	1	1	1	
						
	d= (w + x + z')(w + x + y')			d=(x + w) + z'y'		
```
```						
Seg e		YZ				
		00	01	11	10	
WX	00	1	0	0	1	
	01	1	1	1	1	
	11	1	1	1	1	
	10	1	1	1	1	
						
	e= (w + x + z')					
```						
```						
Seg f		YZ				
		00	01	11	10	
WX	00	0	0	0	1	
	01	1	1	1	1	
	11	1	1	1	1	
	10	1	1	1	1	
						
	f= (w + x + y)(w + x + z')			f=(w + x) + yz'		
```						
```						
Seg g		YZ				
		00	01	11	10	
WX	00	0	0	0	1	
	01	1	1	1	1	
	11	1	1	1	1	
	10	1	1	1	1	
						
	g= (w + x + y)(w + x + z')			f=(w + x) + yz'		Igual a la f
```



## 7. Simulación en Proteus

### 7.1 Archivo de Simulación

El archivo `.pdsprj` contiene todo el circuito consolidado.

Ruta sugerida:

```
[/simulacion/Practica1_G7.pdsprj](https://github.com/CristoferNova/ORGA_G7_DIC2025/blob/main/Practica1_Grupo7.pdsprj)

```

### 7.2 Resultados

* Los segmentos activan correctamente según las entradas.
* Los términos mínimos se validaron visualmente en Proteus.

---

## 8. Implementación Física

### 8.1 Montaje en Protoboard

* Se emplearon ICs TTL 74xx.
* Alimentación de **5 V DC**.
* Distribución ordenada de señales, Vcc y GND.
![Imagen de WhatsApp 2025-12-08 a las 16 37 03_7fbdf1dc](https://github.com/user-attachments/assets/4f6e5da2-16c2-4be3-949a-7be1d4709a76)
![Imagen de WhatsApp 2025-12-07 a las 16 17 29_84d48281](https://github.com/user-attachments/assets/b00648e7-ac4b-4f17-b02f-921b488fd801)
![Imagen de WhatsApp 2025-12-08 a las 16 37 03_dfc89f8e](https://github.com/user-attachments/assets/367820e0-8f44-4829-87f6-d69aaf6d8a08)
![Imagen de WhatsApp 2025-12-07 a las 16 18 00_aa408bf0](https://github.com/user-attachments/assets/c48abde2-caff-431f-afd7-2ae408fd5998)



### 8.2 Validación

* Cada número se probó manualmente.
* El sistema enciende correctamente segmentos frontales y traseros.

---

## 9. Presupuesto

| Componente               | Cantidad | Precio Unitario |       Total |
| ------------------------ | -------: | --------------: | ----------: |
| Protoboard               |        2 |          Q35.00 |      Q70.00 |
| IC TTL 74xx              |        6 |          Q10.00 |      Q60.00 |
| Resistencias 220 Ω       |       20 |           Q0.50 |      Q10.00 |
| Displays 7 Seg(Anodo Y Catodo).          |        2 |          Q15.00 |      Q30.00 |
| Cableado UTP               |        1 |          Q58.50 |      Q58.50 |
| **Costo Total Estimado** |          |                 | **Q228.00** |

---

## 10. Aportes Individuales

| Integrante     | Aporte                                 |
| -------------- | -------------------------------------- |
| Cristofer Eduardo Nova Aguirre | protoboard y documentación |
| Cristopher Alberto LeónEspaña   | Mapas Karnaugh y funciones booleanas   |
| Saúl Andrés Monroy Marroquín   | Simulación en Proteus                  |
| Jose Gustavo Alvarez Sequen   | Video explicativo y presupuesto        |

---

## 11. Conclusiones

* Se logró implementar exitosamente el sistema visualizador bidireccional.
* Los mapas de Karnaugh permitieron minimizar la cantidad de compuertas utilizadas.
* La simulación en Proteus se consolidó en un único archivo funcional.
* El montaje físico cumplió los requerimientos de activación de segmentos.

---

## 12. Anexos

* `https://github.com/CristoferNova/ORGA_G7_DIC2025/blob/main/Practica1_Grupo7.pdsprj`
   <img width="605" height="606" alt="image" src="https://github.com/user-attachments/assets/3d089b6b-bf1f-4341-98ca-a3673373b9a0" />
<img width="869" height="548" alt="image" src="https://github.com/user-attachments/assets/d42f565c-16d2-4be0-a90c-794fcdf56712" />

* `/video/enlace_video.txt`

---



