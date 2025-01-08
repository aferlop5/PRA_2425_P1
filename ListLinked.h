#ifndef LISTLINKED_H
#define LISTLINKED_H

#include "List.h"
#include "Node.h"
#include <stdexcept>
#include <ostream>

// Clase derivada que implementa List<T> con nodos enlazados
template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first; // Puntero al primer nodo
    int n;          // Número de elementos en la lista

public:
    // Constructor
    ListLinked() : first(nullptr), n(0) {}

    // Destructor
    ~ListLinked() {
        Node<T>* aux;
        while (first != nullptr) {
            aux = first->next;
            delete first;
            first = aux;
        }
    }

    // Inserta un elemento en la posición especificada
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Position out of range");
        }

        Node<T>* newNode = new Node<T>(e);

        if (pos == 0) {
            newNode->next = first;
            first = newNode;
        } else {
            Node<T>* current = first;
            for (int i = 0; i < pos - 1; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

        ++n;
    }

    // Añade un elemento al final de la lista
    void append(T e) override {
        insert(n, e);
    }

    // Añade un elemento al principio de la lista
    void prepend(T e) override {
        insert(0, e);
    }

    // Elimina y devuelve un elemento en la posición especificada
    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Position out of range");
        }

        Node<T>* toDelete;
        T removedData;

        if (pos == 0) {
            toDelete = first;
            first = first->next;
        } else {
            Node<T>* current = first;
            for (int i = 0; i < pos - 1; ++i) {
                current = current->next;
            }
            toDelete = current->next;
            current->next = toDelete->next;
        }

        removedData = toDelete->data;
        delete toDelete;
        --n;

        return removedData;
    }

    // Devuelve el elemento en la posición especificada
    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Position out of range");
        }

        Node<T>* current = first;
        for (int i = 0; i < pos; ++i) {
            current = current->next;
        }

        return current->data;
    }

    // Devuelve la posición de la primera ocurrencia de un elemento
    int search(T e) override {
        Node<T>* current = first;
        for (int i = 0; i < n; ++i) {
            if (current->data == e) {
                return i;
            }
            current = current->next;
        }
        return -1;
    }

    // Indica si la lista está vacía
    bool empty() override {
        return n == 0;
    }

    // Devuelve el número de elementos de la lista
    int size() override {
        return n;
    }

    // Sobrecarga del operador []
    T operator[](int pos) {
        return get(pos);
    }

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
        Node<T>* current = list.first;
        out << "[";
        while (current != nullptr) {
            out << current->data;
            if (current->next != nullptr) {
                out << ", ";
            }
            current = current->next;
        }
        out << "]";
        return out;
    }
};

#endif // LISTLINKED_H

