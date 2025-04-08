# Ejercicio de Preparación: Serialización de Árbol de Búsqueda Binaria

Este es un ejercicio de preparación para la Tarea 1, centrado en la serialización y deserialización de una estructura de árbol de búsqueda binaria (BST) a un archivo binario.

## Estructura del Proyecto

```
Preparacion/
│
├── include/ # Archivos de cabecera (.hpp)
│ └── tree.hpp # Definición de la estructura TreeNode y clases
│
├── src/ # Código fuente (.cpp)
│ ├── create_tree.cpp # Programa para crear y serializar el BST
│ ├── search_value.cpp # Programa para buscar un valor en el BST
│ └── tree.cpp # Implementación de BinarySearchTree y TreeUtils
│
├── Makefile # Instrucciones simples de compilación
└── README.md # Este archivo
```

**Nota**: Los ejecutables `create_tree` y `search_value` se generarán en la raíz del proyecto al compilar. El archivo `tree.bin` también se generará en la raíz cuando ejecutes el programa `create_tree`. Esto es intencional para facilitar el trabajo con el ejercicio.

## Compilación

Para compilar los programas, ejecuta:

```bash
make
```

Esto generará dos ejecutables en la raíz del proyecto:

- `create_tree`: Programa para crear y serializar el árbol de búsqueda binaria
- `search_value`: Programa para buscar un valor en el árbol de búsqueda binaria

## Uso

### 1. Crear y serializar el árbol

```bash
./create_tree
```

Este comando creará el archivo `tree.bin` en la raíz del proyecto.
Se puede modificar el árbol en el archivo `src/create_tree.cpp`.

### 2. Buscar un valor en el árbol BST

```bash
./search_value X
```

Donde `X` es el valor que deseas buscar en el árbol.

Por ejemplo, para buscar el valor `80`:

```bash
./search_value 80
```

Lo que debería imprimir:

```bash
Buscando valor 80:
Nodo: id=7, value=80
  No tiene hijo izquierdo
  Hijo derecho: id=9, value=90
```

## Limpieza

Para limpiar los archivos generados:

```bash
make clean
```
