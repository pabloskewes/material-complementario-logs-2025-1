#include "../include/tree.hpp"

// Implementación de BinaryTree
BinarySearchTree::BinarySearchTree(const std::string &filename) {
  this->filename = filename;
}

TreeNode BinarySearchTree::read_node_at(int offset) const {
  TreeNode node;
  std::ifstream in(filename, std::ios::binary);
  if (!in.is_open()) {
    std::cerr << "Error al abrir archivo para lectura: " << filename
              << std::endl;
    std::exit(1);
  }

  std::streampos file_offset = offset * sizeof(TreeNode);
  in.seekg(file_offset);
  in.read(reinterpret_cast<char *>(&node), sizeof(TreeNode));

  if (!in) {
    std::cerr << "Error al leer nodo en posición " << offset << std::endl;
    std::exit(1);
  }

  return node;
}

TreeNode BinarySearchTree::search(int value, int offset) const {
  // Si llegamos a un hijo que no existe, retornamos un nodo inválido
  if (offset == -1) {
    // Retornamos un nodo inválido con id=-1
    return TreeNode{-1, -1, -1, -1};
  }

  // Leemos el nodo actual
  TreeNode node = read_node_at(offset);

  // Comparamos el valor buscado con el valor del nodo actual
  if (value == node.value) {
    // Encontramos el valor
    return node;
  } else if (value < node.value) {
    // El valor es menor, buscamos en el subárbol izquierdo
    return search(value, node.left_child);
  } else {
    // El valor es mayor, buscamos en el subárbol derecho
    return search(value, node.right_child);
  }
}

// Implementación de TreeUtils
namespace TreeUtils {

void write_tree_to_file(
    const std::string &filename,
    const std::vector<TreeNode> &nodes
) {
  std::ofstream out(filename, std::ios::binary);
  if (!out.is_open()) {
    std::cerr << "Error al abrir archivo para escritura: " << filename
              << std::endl;
    std::exit(1);
  }

  for (const TreeNode &node : nodes) {
    out.write(reinterpret_cast<const char *>(&node), sizeof(TreeNode));
  }

  out.close();
}

void print_node_info(const TreeNode &node, const BinarySearchTree &tree) {
  if (node.id == -1) {
    std::cout << "Nodo inválido o no encontrado" << std::endl;
    return;
  }

  std::cout << "Nodo: id=" << node.id << ", value=" << node.value << std::endl;

  // Mostrar información sobre los hijos
  if (node.left_child != -1) {
    TreeNode left = tree.read_node_at(node.left_child);
    std::cout << "  Hijo izquierdo: id=" << left.id << ", value=" << left.value
              << std::endl;
  } else {
    std::cout << "  No tiene hijo izquierdo" << std::endl;
  }

  if (node.right_child != -1) {
    TreeNode right = tree.read_node_at(node.right_child);
    std::cout << "  Hijo derecho: id=" << right.id << ", value=" << right.value
              << std::endl;
  } else {
    std::cout << "  No tiene hijo derecho" << std::endl;
  }
}

} // namespace TreeUtils
