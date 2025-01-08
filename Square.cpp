#include "Square.h"
#include "Point2D.h"
#include <cmath>

// Verifica si los vértices forman un cuadrado válido
bool Square::check(Point2D* vertices) {
    // Calcular las distancias entre los vértices
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);

    // Las cuatro aristas deben ser del mismo tamaño
    return (d01 == d12 && d12 == d23 && d23 == d30);
}

// Constructor por defecto, crea un cuadrado con los vértices dados
Square::Square() : Rectangle("red", new Point2D[4]{Point2D(-1, 1), Point2D(1, 1), Point2D(1, -1), Point2D(-1, -1)}) {}

// Constructor con parámetros, verifica la validez del cuadrado
Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices no forman un cuadrado válido");
    }
}

// Sobreescribir el método set_vertices para asegurarse de que los vértices forman un cuadrado
void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices no forman un cuadrado válido");
    }
    Rectangle::set_vertices(vertices);  // Llamar al método de la clase base
}

// Sobrecarga del operador << para imprimir el cuadrado
std::ostream& operator<<(std::ostream &out, const Square &square) {
    out << "Square [Color: " << square.get_color() << ", Vertices: ";
    for (int i = 0; i < Rectangle::N_VERTICES; ++i) {  // Reutilizamos el número de vértices de Rectangle
        out << square.get_vertex(i) << " ";  // Usamos get_vertex para acceder a los vértices
    }
    out << "]";
    return out;
}


