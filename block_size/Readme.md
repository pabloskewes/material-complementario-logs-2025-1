# block_size

Este directorio contiene una utilidad para obtener el tamaño real del bloque (`B`) del sistema de archivos, usado en el modelo de memoria externa.

## ¿Cómo obtener `B` desde la terminal?

### En macOS

```bash
stat -f "%k" .
```

→ Ya está en bytes. Ejemplo: `4096`

### En Linux (Ubuntu)

```bash
stat -f --format="%S" .
```

→ También entrega el tamaño del bloque en bytes. Ejemplo: `4096`

## ¿Y si quiero hacerlo desde C++?

Puedes usar el archivo `block_size.h`, que incluye una función portable para obtener `B` ejecutando `stat` internamente.

Solo tienes que incluirlo en tu proyecto y usarlo como en el siguiente ejemplo:

```cpp
#include <iostream>
#include "block_size.h"

int main() {
    long B = get_block_size();
    if (B <= 0) {
        std::cerr << "Error al obtener B" << std::endl;
        return 1;
    }
    std::cout << "Tamaño de bloque (B): " << B << " bytes" << std::endl;
    return 0;
}
```

## Cómo probarlo

Desde esta carpeta:

```bash
g++ -O2 -o block_test main.cpp
./block_test
```

Deberías ver una salida como:

```
Tamaño de bloque (B): 4096 bytes
```

Debería funcionar tanto en macOS como en Linux, incluyendo dentro de contenedores Docker como los usados en el curso.
