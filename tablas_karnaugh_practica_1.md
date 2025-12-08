# Tablas de Verdad, Mapas de Karnaugh y Expresiones 

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
# 1) Tablas de verdad Modo Normal

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
# 2) Mapas de Karnaugh y Expresiones Modo Normal
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
# 3) Tablas de verdad Modo espejo

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
# 2) Mapas de Karnaugh y Expresiones Modo Espejo
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

## Cátodo común — **SOP (términos mínimos)**
```
a= w'x'
b= w'x'y' + w'x'z	b= w'x'(y'+z)	
c= w'x'z
d=  w'x'z + w'x'y		d= w'x'(y+z)	
e=w'x' 	mismo que el a	
f=w'x'z' 
g= w'x'y' + w'x'z		g=w'x'(y'+z)		mismo que el b
```
---
## Ánodo común — **POS (términos máximos)**
```
a= (w+x)
b= (w+x+z)
c= (w + x)	igual que el a	
d= (w + x + z')(w + x + y')			d=(x + w) + z'y'	
e= (w + x + z')	
f= (w + x + y)(w + x + z')			f=(w + x) + yz'	
g= (w + x + y)(w + x + z')			f=(w + x) + yz'		Igual a la f

```

---
