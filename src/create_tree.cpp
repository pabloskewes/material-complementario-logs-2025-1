// create_tree.cpp
#include "../include/tree.hpp"
#include <iostream>
#include <vector>

/**
 * @brief Crea un árbol de búsqueda binaria (BST) de ejemplo
 *
 * Estructura del árbol:
 *          (1,50)
 *         /     \
 *     (2,30)    (3,70)
 *     /    \       /  \
 * (4,20)  (5,40) (6,60) (7,80)
 *   /                     \
 * (8,10)                 (9,90)
 *
 * En un BST, para cada nodo:
 * - Todos los valores en su subárbol izquierdo son menores que el valor del
 * nodo
 * - Todos los valores en su subárbol derecho son mayores que el valor del nodo
 *
 * @return std::vector<TreeNode> Vector con los nodos en recorrido preorden
 */
std::vector<TreeNode> create_sample_tree() {
  std::vector<TreeNode> tree_nodes = {
      {1, 50, 1, 5},   // root (index 0)
      {2, 30, 2, 4},   // left child of root (index 1)
      {4, 20, 3, -1},  // left child is node 10 (index 3)
      {8, 10, -1, -1}, // left child of node 4 (index 3)
      {5, 40, -1, -1}, // right child of node 2 (index 4)
      {3, 70, 6, 7},   // right child of root (index 5)
      {6, 60, -1, -1}, // left child of node 3 (index 6)
      {7, 80, -1, 8},  // right child of node 3 (index 7)
      {9, 90, -1, -1}  // right child of node 7 (index 8)
  };

  return tree_nodes;
}

int main() {
  const std::string filename = "tree.bin";

  // Creamos el árbol usando la función auxiliar
  std::vector<TreeNode> tree_nodes = create_sample_tree();

  // Serializamos el árbol a disco
  TreeUtils::write_tree_to_file(filename, tree_nodes);

  std::cout << "Árbol de búsqueda binaria serializado en '" << filename << "'."
            << std::endl;
  std::cout << "Estructura del árbol:" << std::endl;
  std::cout << "          (1,50)" << std::endl;
  std::cout << "         /     \\" << std::endl;
  std::cout << "     (2,30)    (3,70)" << std::endl;
  std::cout << "     /    \\       /  \\" << std::endl;
  std::cout << "(4,20)  (5,40) (6,60) (7,80)" << std::endl;
  std::cout << "  /                     \\" << std::endl;
  std::cout << "(8,10)                 (9,90)" << std::endl;

  return 0;
}
