#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <stdexcept>
#include <ostream>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;  // Puntero al array que almacena los elementos
    int max;  // Tamaño actual del array
    int n;    // Número de elementos en la lista
    static const int MINSIZE = 2;  // Tamaño mínimo del array

    // Método privado para redimensionar el array
    void resize(int new_size) {
        T* new_arr = new T[new_size];  // Crear nuevo array
        for (int i = 0; i < n; ++i) {
            new_arr[i] = arr[i];  // Copiar los elementos
        }
        delete[] arr;  // Liberar la memoria del viejo array
        arr = new_arr;  // Actualizar el puntero
        max = new_size;  // Actualizar el tamaño máximo
    }

public:
    // Constructor sin argumentos
    ListArray() {
        arr = new T[MINSIZE];
        max = MINSIZE;
        n = 0;
    }

    // Destructor
    ~ListArray() {
        delete[] arr;
    }

    // Implementación de los métodos de la interfaz List<T>

    // Inserta un elemento en una posición dada
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición fuera de rango");
        }
        if (n == max) {  // Si el array está lleno, lo redimensionamos
            resize(max * 2);  // Duplicamos el tamaño
        }
        for (int i = n; i > pos; --i) {
            arr[i] = arr[i - 1];  // Desplazar los elementos hacia la derecha
        }
        arr[pos] = e;  // Insertar el nuevo elemento
        ++n;
    }

    // Inserta un elemento al final de la lista
    void append(T e) override {
        insert(n, e);  // append es un caso particular de insert
    }

    // Inserta un elemento al principio de la lista
    void prepend(T e) override {
        insert(0, e);  // prepend es un caso particular de insert
    }

    // Elimina y devuelve el elemento en una posición dada
    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango");
        }
        T removed_element = arr[pos];
        for (int i = pos; i < n - 1; ++i) {
            arr[i] = arr[i + 1];  // Desplazar los elementos hacia la izquierda
        }
        --n;
        if (n < max / 4 && max / 2 >= MINSIZE) {
            resize(max / 2);  // Reducir el tamaño si está demasiado vacío
        }
        return removed_element;
    }

    // Devuelve el elemento en una posición dada
    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango");
        }
        return arr[pos];
    }

    // Busca un elemento y devuelve su posición
    int search(T e) override {
        for (int i = 0; i < n; ++i) {
            if (arr[i] == e) {
                return i;
            }
        }
        return -1;  // Elemento no encontrado
    }

    // Devuelve true si la lista está vacía
    bool empty() override {
        return n == 0;
    }

    // Devuelve el número de elementos en la lista
    int size() override {
        return n;
    }

    // Sobrecarga del operador []
    T operator[](int pos) {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango");
        }
        return arr[pos];
    }

    // Sobrecarga global del operador << para imprimir la lista
    friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
        out << "[";
        for (int i = 0; i < list.n; ++i) {
            out << list.arr[i];
            if (i < list.n - 1) {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }
};

#endif  // LISTARRAY_H

