# Tablas de Verdad, Mapas de Karnaugh y Expresiones

Este documento contiene:
- Tablas de verdad de segmentos `a–g`
- Mapas de Karnaugh (ASCII)
- Expresiones simplificadas (SOP y POS)

---
## Convenciones utilizadas

Entradas:
```
A = bit menos significativo (LSB)
B = siguiente bit
C = siguiente bit
D = bit más significativo (MSB)
```

Índice de minterm:
```
index = A + 2B + 4C + 8D
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
D C B A | a
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
D C B A | b
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
D C B A | c
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
D C B A | d
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
D C B A | e
0 0 0 0 | 1
0 0 1 0 | 1
0 1 1 0 | 1
1 0 0 0 | 1
otros | X
```

## Segmento **f**
Minterms = `0,4,5,6,8,9`

```
D C B A | f
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
D C B A | g
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
      BC
     00 01 11 10
D A +----------------
0 0 | 1  0  1  0
0 1 | 0  1  1  0
1 0 | 1  X  X  X
1 1 | 1  X  X  X
```

---
## Segmento **b**

```
      BC
     00 01 11 10
D A +----------------
0 0 | 1  1  1  0
0 1 | 0  0  0  1
1 0 | 1  X  X  X
1 1 | 1  X  X  X
```

---
## Segmento **c**

```
      BC
     00 01 11 10
D A +----------------
0 0 | 1  1  1  0
0 1 | 0  0  0  1
1 0 | 1  X  X  X
1 1 | 1  X  X  X
```

---
## Segmento **d**

```
      BC
     00 01 11 10
D A +----------------
0 0 | 1  0  1  0
0 1 | 0  1  1  0
1 0 | 1  X  X  X
1 1 | 1  X  X  X
```

---
## Segmento **e**

```
      BC
     00 01 11 10
D A +----------------
0 0 | 1  0  0  0
0 1 | 0  0  0  0
1 0 | 1  X  X  X
1 1 | X  X  X  X
```

---
## Segmento **f**

```
      BC
     00 01 11 10
D A +----------------
0 0 | 1  0  0  0
0 1 | 1  1  0  0
1 0 | 1  X  X  X
1 1 | 1  X  X  X
```

---
## Segmento **g**

```
      BC
     00 01 11 10
D A +----------------
0 0 | 0  0  1  0
0 1 | 1  1  1  0
1 0 | 1  X  X  X
1 1 | 1  X  X  X
```

---
# 3) Expresiones simplificadas

## Cátodo común — **SOP (términos mínimos)**
```
a = A + C + (B·D) + (B'·D')
b = B' + (C·D) + (C'·D')
c = B + D + C'
d = A + (C·B') + (C·D') + (B'·D') + (B·D·C')
e = (C·D') + (B'·D')
f = A + (B·C') + (B·D') + (C'·D')
g = A + (B·C') + (C·B') + (C·D')
```

---
## Ánodo común — **POS (términos máximos)**
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
# Listo para incluir en el informe

Puedes copiar/pegar este contenido directamente en tu documento o exportarlo a PDF junto con imágenes.

Si deseas que genere **los mapas como imagen (.png)** para subir a la carpeta `/documentacion/imagenes/`, indícame 👍

