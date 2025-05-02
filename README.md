# Material Complementario – CC4102 (Otoño 2025)

Repositorio con material complementario para el curso **Diseño y Análisis de Algoritmos (CC4102)** de la **FCFM, Universidad de Chile**, semestre de otoño 2025.

## Contenido

### `serializacion_bst/`

Ejercicio de preparación para la Tarea 1, sobre serialización de árboles binarios en disco usando C++.

- `enunciado/`: contiene la descripción del ejercicio.
- `include/`: definiciones de estructuras y clases.
- `src/`: código para crear un árbol, buscar valores y serializar/deserializar.
  - El archivo `tree.cpp` debe ser implementado por el estudiante. Puede usar `tree_templ.cpp` como base.

Más información en el [enunciado del ejercicio](serializacion_bst/enunciado/ejercicio_preparacion.pdf).

### `quicksort_tornillos_y_tuercas/`

Implementación del algoritmo de quicksort para ordenar tornillos y tuercas vista en el `Aux2-P1-b`.

- `quicksort.ipynb`: notebook con el código.

### `block_size/`

Herramienta para obtener el tamaño real del bloque (`B`) del sistema de archivos, usado en el modelo de memoria externa.

Incluye formas de obtener `B` desde terminal (usando `stat`) y desde C++ (mediante la función `get_block_size()`). Útil para las tareas de memoria externa donde se necesita conocer este valor. Más información en el [README del directorio](block_size/Readme.md).

### `disk_read_test/`

Programa para experimentar con el comportamiento del sistema operativo respecto al **caching de archivos** y simular condiciones en las que archivos grandes no caben en memoria principal.

Útil para ver el efecto de caché del sistema operativo, lo ideal es que para las tareas de memoria externa, haya la menor cantidad de caché posible, para que los experimentos sean lo más reales posible. Más información en el [README del directorio](disk_read_test/README.md).

### `dudas_tarea/`

Material complementario y aclaraciones sobre las tareas del curso.
