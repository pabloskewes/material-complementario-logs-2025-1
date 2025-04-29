## disk_read_test

### Descripción

Este programa permite:

- Generar un archivo binario de números aleatorios de 64 bits, de tamaño configurable (en MB).
- Leer ese archivo en bloques de 1 MB y medir el tiempo de lectura.

El objetivo es experimentar con el comportamiento del sistema operativo respecto al **caching de archivos**, y simular condiciones en las que el archivo **no cabe en memoria principal**, forzando accesos a disco.

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

Esto crea un archivo binario llamado `archivo.bin` de **1.5 GB** (1536 MB), lleno de enteros aleatorios de 64 bits.

---

#### 2. Leer el archivo

```bash
./disk_read_test --read archivo.bin
```

Esto leerá el archivo dos veces, midiendo el tiempo de lectura en cada pasada.

- La segunda lectura suele ser significativamente más rápida, lo que indica que el sistema operativo ha cacheado el archivo.
- Si ambas lecturas toman tiempos similares, es probable que se esté leyendo desde disco en ambas ocasiones.

---

#### 3. Limitar memoria

Para simular que el archivo no cabe en memoria, se puede ejecutar el programa en un contenedor con solo **50 MB de memoria disponible**:

```bash
docker run --rm -it -m 50m -v "$PWD":/workspace pabloskewes/cc4102-cpp-env bash
```

Este comando realiza lo siguiente:

- Descarga automáticamente una imagen de Docker con todo lo necesario para compilar y ejecutar el programa.
- Limita la memoria del contenedor a 50 MB.
- Monta el directorio actual en el contenedor bajo `/workspace`.
- Abre una terminal interactiva dentro del contenedor.

Al ingresar, debería aparecer algo como:

```
root@<hash>:/workspace#
```

A partir de ese punto, se debe recompilar el programa dentro del contenedor y ejecutar los comandos como antes.

---

### Resultado esperado

Los tiempos pueden variar, pero el comportamiento debería ser similar.

#### Ejecución normal:

```
First read:
Read 1536 MB in 585 ms
Second read (may be cached):
Read 1536 MB in 337 ms
```

#### Ejecución con límite de memoria:

```
First read:
Read 1536 MB in 851 ms
Second read (may be cached):
Read 1536 MB in 775 ms
```

En esta segunda ejecución, los tiempos de lectura son similares, lo que indica que el sistema operativo no pudo cachear completamente el archivo, como era de esperarse bajo condiciones de memoria limitada.

---

### Notas adicionales

- El programa utiliza bloques de 1 MB para leer el archivo, definidos por la constante `BUFFER_SIZE`.
- La imagen de Docker se puede encontrar en [pabloskewes/cc4102-cpp-env](https://hub.docker.com/r/pabloskewes/cc4102-cpp-env). Debería bastar para cualquier programa simple de C++.
