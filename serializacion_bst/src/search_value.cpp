// search_value.cpp
#include "../include/tree.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Uso: ./search_value <valor>" << std::endl;
    return 1;
  }

  int value = std::atoi(argv[1]);
  const std::string filename = "tree.bin";

  // Crear un objeto BinarySearchTree para buscar en el archivo
  BinarySearchTree tree(filename);

  std::cout << "Buscando valor " << value << ":" << std::endl;
  TreeNode result = tree.search(value);

  // Imprimir información detallada del nodo encontrado
  TreeUtils::print_node_info(result, tree);

  return 0;
}