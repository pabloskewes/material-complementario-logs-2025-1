#ifndef TREE_HPP
#define TREE_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Estructura que representa un nodo del BST en disco
 *
 * Cada nodo contiene:
 * - id: Identificador único del nodo
 * - value: Valor almacenado en el nodo
 * - left_child: Posición del hijo izquierdo en el archivo (-1 si no tiene)
 * - right_child: Posición del hijo derecho en el archivo (-1 si no tiene)
 */
struct TreeNode {
  int id;
  int value;
  long left_child;
  long right_child;
};

/**
 * @brief Clase que representa un BST almacenado en disco
 *
 * Esta clase permite navegar un BST guardado en un archivo binario.
 */
class BinarySearchTree {
public:
  /**
   * @brief Construye un BST a partir de un archivo binario
   * @param filename Nombre del archivo que contiene el BST
   */
  BinarySearchTree(const std::string &filename);

  /**
   * @brief Lee y deserializa un nodo del BST desde una posición específica
   * del archivo binario
   *
   * Esta función calcula la posición exacta en bytes en el archivo binario a
   * partir del índice proporcionado, lee los bytes correspondientes a un nodo,
   * y los deserializa para reconstruir la estructura TreeNode en memoria.
   * Es responsabilidad del usuario asegurarse de que el offset sea válido,
   * es decir, que exista un nodo en esa posición.
   *
   * @param offset Posición del nodo en el archivo (índice en preorden,
   * comenzando desde 0)
   * @return TreeNode El nodo deserializado desde el archivo
   * @throws Termina el programa si no puede abrir el archivo o leer los bytes
   * del nodo
   */
  TreeNode read_node_at(int offset) const;

  /**
   * @brief Busca un valor en el BST desde un nodo específico
   *
   * Esta función implementa una búsqueda binaria en el BST, leyendo solo
   * los nodos necesarios desde el archivo. Si se omite el offset, comienza
   * desde la raíz (offset 0).
   *
   * @param value Valor a buscar en el BST
   * @param offset Posición del nodo inicial (por defecto 0, la raíz)
   * @return TreeNode con el valor buscado, o un nodo con id=-1 si no se
   * encuentra
   */
  TreeNode search(int value, int offset = 0) const;

private:
  std::string filename;
};

namespace TreeUtils {

/**
 * @brief Serializa y escribe un BST en un archivo binario
 *
 * Esta función recibe un vector de nodos en recorrido preorden y los escribe
 * secuencialmente en un archivo binario. Cada nodo ocupa sizeof(TreeNode)
 * bytes. Los campos left_child y right_child indican los índices de los hijos
 * en el recorrido preorden.
 *
 * @param filename Nombre del archivo donde se escribirá el BST
 * @param nodes Vector de nodos en recorrido preorden
 * @throws Termina el programa si no puede abrir el archivo
 */
void write_tree_to_file(
    const std::string &filename,
    const std::vector<TreeNode> &nodes
);

/**
 * @brief Imprime información detallada de un nodo del BST
 *
 * Esta función muestra el id y valor del nodo, así como información
 * sobre sus hijos si existen.
 *
 * @param node Nodo a imprimir
 * @param tree BST al que pertenece el nodo (para leer los hijos)
 */
void print_node_info(const TreeNode &node, const BinarySearchTree &tree);

} // namespace TreeUtils

#endif // TREE_HPP
