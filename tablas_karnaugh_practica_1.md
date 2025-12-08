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
0 = 0000
1 = 0001
2 = 0010
...
9 = 1001
```

Valores 10–15 se toman como **don't care (X)**.

---
# 1) Tablas de verdad por segmento

## Segmento **a**
Minterms = `0,2,3,5,6,7,8,9`

```
Z Y X W | a
0 0 0 0 | 1
0 0 0 1 | 0
0 0 1 0 | 1
0 0 1 1 | 1
0 1 0 0 | 0
0 1 0 1 | 1
0 1 1 0 | 1
0 1 1 1 | 1
1 0 0 0 | 1
1 0 0 1 | 1
otros  (10–15) | X
```

## Segmento **b**
Minterms = `0,1,2,3,4,7,8,9`

```
Z Y X W | b
0 0 0 0 | 1
0 0 0 1 | 1
0 0 1 0 | 1
0 0 1 1 | 1
0 1 0 0 | 1
0 1 1 1 | 1
1 0 0 0 | 1
1 0 0 1 | 1
otros | X
```

## Segmento **c**
Minterms = `0,1,3,4,5,6,7,8,9`

```
Z Y X W | c
0 0 0 0 | 1
0 0 0 1 | 1
0 0 1 1 | 1
0 1 0 0 | 1
0 1 0 1 | 1
0 1 1 0 | 1
0 1 1 1 | 1
1 0 0 0 | 1
1 0 0 1 | 1
otros | X
```

## Segmento **d**
Minterms = `0,2,3,5,6,8,9`

```
Z Y X W | d
0 0 0 0 | 1
0 0 1 0 | 1
0 0 1 1 | 1
0 1 0 1 | 1
0 1 1 0 | 1
1 0 0 0 | 1
1 0 0 1 | 1
otros | X
```

## Segmento **e**
Minterms = `0,2,6,8`

```
Z Y X W | e
0 0 0 0 | 1
0 0 1 0 | 1
0 1 1 0 | 1
1 0 0 0 | 1
otros | X
```

## Segmento **f**
Minterms = `0,4,5,6,8,9`

```
Z Y X W | f
0 0 0 0 | 1
0 1 0 0 | 1
0 1 0 1 | 1
0 1 1 0 | 1
1 0 0 0 | 1
1 0 0 1 | 1
otros | X
```

## Segmento **g**
Minterms = `2,3,4,5,6,8,9`

```
Z Y X W | g
0 0 1 0 | 1
0 0 1 1 | 1
0 1 0 0 | 1
0 1 0 1 | 1
0 1 1 0 | 1
1 0 0 0 | 1
1 0 0 1 | 1
otros | X
```

---
# 2) Mapas de Karnaugh (ASCII)

## Segmento **a**

```
	YZ			
		00	01	11	10
WX	00	1	1	1	1
	01	0	0	0	0
	11	0	0	0	0
	10	0	0	0	0
<img width="481" height="162" alt="image" src="https://github.com/user-attachments/assets/87aaa439-af9b-43b0-9e2f-553bb2604bb2" />

```

---
## Segmento **b**

```
      XY
     00 01 11 10
Z W +----------------
0 0 | 1  1  1  0
0 1 | 0  0  0  1
1 0 | 1  X  X  X
1 1 | 1  X  X  X
```

---
## Segmento **c**

```
      XY
     00 01 11 10
Z W +----------------
0 0 | 1  1  1  0
0 1 | 0  0  0  1
1 0 | 1  X  X  X
1 1 | 1  X  X  X
```

---
## Segmento **d**

```
      XY
     00 01 11 10
Z W +----------------
0 0 | 1  0  1  0
0 1 | 0  1  1  0
1 0 | 1  X  X  X
1 1 | 1  X  X  X
```

---
## Segmento **e**

```
      XY
     00 01 11 10
Z W +----------------
0 0 | 1  0  0  0
0 1 | 0  0  0  0
1 0 | 1  X  X  X
1 1 | X  X  X  X
```

---
## Segmento **f**

```
      XY
     00 01 11 10
Z W +----------------
0 0 | 1  0  0  0
0 1 | 1  1  0  0
1 0 | 1  X  X  X
1 1 | 1  X  X  X
```

---
## Segmento **g**

```
      XY
     00 01 11 10
Z W +----------------
0 0 | 0  0  1  0
0 1 | 1  1  1  0
1 0 | 1  X  X  X
1 1 | 1  X  X  X
```

---
# 3) Expresiones simplificadas

## Cátodo común — **SOP (términos mínimos)**
```
a = W + Y + (X·Z) + (X'·Z')
b = X' + (Y·Z) + (Y'·Z')
c = X + Z + Y'
d = W + (Y·X') + (Y·Z') + (X'·Z') + (X·Z·Y')
e = (Y·Z') + (X'·Z')
f = W + (X·Y') + (X·Z') + (Y'·Z')
g = W + (X·Y') + (Y·X') + (Y·Z')
```

---
## Ánodo común — **POS (términos máximos)**
```
a = W' · Y' · (X + Z) · (X' + Z')
b = X · (Y + Z) · (Y' + Z')
c = Y · X' · Z'
d = W' · (X + Z) · (X + Y') · (Z + Y') · (Y + X' + Z')
e = (X + Z) · (Z + Y')
f = W' · (Y + Z) · (Y + X') · (Z + X')
g = W' · (X + Y') · (Y + X') · (Z + Y')
```

---
