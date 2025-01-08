#include "Circle.h"
#include <cmath>  // Para M_PI y sqrt

// Constructor por defecto
Circle::Circle() : Shape("red"), center(0, 0), radius(1) {}

// Constructor con parámetros
Circle::Circle(std::string color, Point2D center, double radius) : Shape(color), center(center), radius(radius) {}

// Obtener el centro
Point2D Circle::get_center() const {
    return center;
}

// Modificar el centro
void Circle::set_center(Point2D p) {
    center = p;
}

// Obtener el radio
double Circle::get_radius() const {
    return radius;
}

// Modificar el radio
void Circle::set_radius(double r) {
    if (r > 0) {
        radius = r;
    } else {
        throw std::invalid_argument("El radio debe ser positivo.");
    }
}

// Calcular el área del círculo
double Circle::area() const {
    return M_PI * std::pow(radius, 2);
}

// Calcular el perímetro del círculo
double Circle::perimeter() const {
    return 2 * M_PI * radius;
}

// Desplazar el círculo
void Circle::translate(double incX, double incY) {
    center.setX(center.getX() + incX);
    center.setY(center.getY() + incY);
}

// Imprimir información del círculo
void Circle::print() const {
    std::cout << "Circle [Color: " << get_color() << ", Center: (" << center.getX() << ", " << center.getY() << "), Radius: " << radius << "]" << std::endl;
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream &out, const Circle &c) {
    out << "Circle [Color: " << c.get_color() << ", Center: (" << c.center.getX() << ", " << c.center.getY() << "), Radius: " << c.radius << "]";
    return out;
}

