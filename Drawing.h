#ifndef DRAWING_H
#define DRAWING_H

#include "Shape.h"  // Asegúrate de incluir la clase Shape y sus derivadas
#include "ListLinked.h"  // La interfaz List<T> y su implementación

class Drawing {
private:
    List<Shape*>* shapes;  // Lista de figuras (Shapes)

public:
    // Constructor
    Drawing();

    // Destructor
    ~Drawing();

    // Método para agregar una figura al frente del dibujo
    void add_front(Shape* shape);

    // Método para agregar una figura al fondo del dibujo
    void add_back(Shape* shape);

    // Método para imprimir información de todas las figuras
    void print_all();

    // Método para obtener el área de todos los círculos en el dibujo
    double get_area_all_circles();

    // Método para mover todos los cuadrados en el dibujo
    void move_squares(double incX, double incY);
};

#endif

