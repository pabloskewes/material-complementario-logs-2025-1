## disk_read_test

### Descripción

Este programa permite:

- Generar un archivo binario de números aleatorios de 64 bits de tamaño configurable (en MB).
- Leer ese archivo en bloques de 1 MB y medir el tiempo de lectura.

El objetivo es experimentar con el comportamiento del sistema operativo respecto al caching de archivos, y simular condiciones donde el archivo no cabe en memoria principal, forzando accesos a disco.

---

### Compilación

```bash
g++ -O2 -o disk_read_test disk_read_test.cpp
```

---

### Uso

#### 1. Generar un archivo binario

```bash
./disk_read_test --generate archivo.bin 1536
```

Esto crea un archivo binario llamado `archivo.bin` de **1.5 GB** (1536 MB), lleno de enteros aleatorios de 64 bits.

---

#### 2. Leer el archivo con límite de memoria

Para simular que el sistema tiene solo **500 MB de memoria disponible para el proceso**, puedes usar:

```bash
ulimit -v 512000     # Limita a 512000 KB = 500 MB
./disk_read_test --read archivo.bin
```

Esto leerá el archivo dos veces, midiendo el tiempo de lectura en cada pasada.

El objetivo es **observar si la segunda lectura es significativamente más rápida** (lo que indicaría que el sistema operativo cacheó el archivo), o si ambas toman tiempos similares (lo que sugiere que se está leyendo desde disco en ambas ocasiones).

---

### Notas

- En **macOS**, el comando `ulimit -v` **no funciona**. El sistema operativo no permite limitar la memoria virtual de un proceso desde la línea de comandos.
- El programa utiliza bloques de 1 MB para leer el archivo, definidos por la constante `BUFFER_SIZE`.
