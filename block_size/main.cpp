#include "block_size.h"
#include <iostream>

int main() {
  long B = get_block_size();
  if (B < 0) {
    std::cerr << "Error al obtener el tamaño de bloque." << std::endl;
    return 1;
  }
  std::cout << "Tamaño de bloque (B): " << B << " bytes" << std::endl;
  return 0;
}
