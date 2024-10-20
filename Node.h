#ifndef NODE_H
#define NODE_H

#include <ostream>

template <typename T>
class Node {
public:
    T data;              // El dato almacenado en el nodo
    Node<T>* next;       // Puntero al siguiente nodo (o nullptr si es el último)

    // Constructor: Inicializa el nodo con un valor y un puntero al siguiente nodo (por defecto nullptr)
    Node(T data, Node<T>* next = nullptr) 
        : data(data), next(next) {}

    // Sobrecarga del operador << para imprimir el contenido de un nodo
    friend std::ostream& operator<<(std::ostream &out, const Node<T> &node) {
        out << node.data;
        return out;
    }
};

#endif  // NODE_H

