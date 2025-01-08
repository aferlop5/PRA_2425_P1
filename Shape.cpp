#include "Shape.h"

// Método para validar colores
void Shape::validate_color(const std::string &c) const {
    if (c != "red" && c != "green" && c != "blue") {
        throw std::invalid_argument("Invalid color: " + c + ". Valid colors are 'red', 'green', 'blue'.");
    }
}

// Constructor por defecto: color rojo
Shape::Shape() : color("red") {}

// Constructor con color especificado
Shape::Shape(const std::string &color) {
    validate_color(color);
    this->color = color;
}

// Obtener color
std::string Shape::get_color() const {
    return color;
}

// Modificar color
void Shape::set_color(const std::string &c) {
    validate_color(c);
    color = c;
}
