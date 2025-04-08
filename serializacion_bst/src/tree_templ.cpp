#include "../include/tree.hpp"

// Implementación de BinarySearchTree

BinarySearchTree::BinarySearchTree(const std::string &filename) {
  // TODO: Inicializar con el nombre del archivo
}

TreeNode BinarySearchTree::read_node_at(int offset) const {
  // TODO: Leer un nodo desde el archivo binario usando el offset
  return TreeNode{-1, -1, -1, -1}; // Placeholder
}

TreeNode BinarySearchTree::search(int value, int offset) const {
  // TODO: Buscar recursivamente el valor a partir del offset dado
  return TreeNode{-1, -1, -1, -1}; // Placeholder
}

// Implementación de TreeUtils

namespace TreeUtils {

void write_tree_to_file(
    const std::string &filename,
    const std::vector<TreeNode> &nodes
) {
  // TODO: Escribir todos los nodos al archivo en formato binario
}

void print_node_info(const TreeNode &node, const BinarySearchTree &tree) {
  // TODO: Imprimir la información del nodo y sus hijos si existen
}

} // namespace TreeUtils
