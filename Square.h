#ifndef SQUARE_H
#define SQUARE_H

#include <stdexcept>
#include <iostream>
#include "Rectangle.h"

class Square : public Rectangle {
private:
    static bool check(Point2D* vertices); // Verifica si los vértices forman un cuadrado válido

public:
    Square();  // Constructor por defecto
    Square(std::string color, Point2D* vertices);  // Constructor con parámetros
    void set_vertices(Point2D* vertices);  // Sobreescribir para modificar los vértices
    friend std::ostream& operator<<(std::ostream& out, const Square& square);  // Sobrecarga de operador <<
};

#endif

