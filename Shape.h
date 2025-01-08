#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <stdexcept>
#include <iostream>
#include "Point2D.h"

class Shape {
protected:
    std::string color;  // Color de la figura: "red", "green", "blue"

    // Método auxiliar para validar colores
    void validate_color(const std::string &c) const;

public:
    // Constructores
    Shape();
    Shape(const std::string &color);

    // Métodos de acceso
    std::string get_color() const;
    void set_color(const std::string &c);

    // Métodos virtuales puros
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void translate(double incX, double incY) = 0;
    virtual void print() const = 0;

    // Destructor virtual para permitir eliminación correcta de objetos derivados
    virtual ~Shape() = default;
};

#endif

