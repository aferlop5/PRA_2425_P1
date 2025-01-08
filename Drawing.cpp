#include "Drawing.h"
#include "Circle.h"
#include "Square.h"
#include <iostream>

// Constructor de Drawing
Drawing::Drawing() {
    shapes = new ListLinked<Shape*>();
}

// Destructor de Drawing
Drawing::~Drawing() {
    // Eliminar figuras de la lista
    for (int i = 0; i < shapes->size(); ++i) {
        delete shapes->get(i);  // Asegúrate de liberar correctamente la memoria
    }
    delete shapes;  // Liberar la memoria de la lista
}


// Método para agregar al frente
void Drawing::add_front(Shape* shape) {
    shapes->prepend(shape);  // Utiliza prepend para agregar al frente
}

// Método para agregar al fondo
void Drawing::add_back(Shape* shape) {
    shapes->append(shape);   // Utiliza append para agregar al fondo
}

// Método para imprimir todas las figuras
void Drawing::print_all() {
    for (int i = 0; i < shapes->size(); ++i) {  // Recorre la lista usando size()
        shapes->get(i)->print();  // Llamada al método print de Shape o sus derivados
    }
}

// Método para obtener el área de todos los círculos
double Drawing::get_area_all_circles() {
    double total_area = 0.0;
    for (int i = 0; i < shapes->size(); ++i) {  // Recorre la lista usando size()
        Circle* circle = dynamic_cast<Circle*>(shapes->get(i));
        if (circle) {
            total_area += circle->area();
        }
    }
    return total_area;
}

// Método para mover todos los cuadrados
void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); ++i) {  // Recorre la lista usando size()
        Square* square = dynamic_cast<Square*>(shapes->get(i));
        if (square) {
            // Accede a los vértices del cuadrado y mueve cada uno
            Point2D* vertices = new Point2D[4];  // Crear un arreglo para los nuevos vértices
            for (int j = 0; j < 4; ++j) {
                Point2D vertex = square->get_vertex(j);  // Obtener el vértice actual
                vertices[j] = Point2D(vertex.getX() + incX, vertex.getY() + incY);  // Mover el vértice
            }
            square->set_vertices(vertices);  // Actualiza los vértices del cuadrado
            delete[] vertices;  // Libera la memoria del arreglo
        }
    }
}

