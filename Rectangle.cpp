#include "Rectangle.h"

// Verifica si los vértices forman un rectángulo válido
bool Rectangle::check(Point2D* vertices) {
    double d1 = Point2D::distance(vertices[0], vertices[1]);  // Distancia entre v0 y v1
    double d2 = Point2D::distance(vertices[1], vertices[2]);  // Distancia entre v1 y v2
    double d3 = Point2D::distance(vertices[2], vertices[3]);  // Distancia entre v2 y v3
    double d4 = Point2D::distance(vertices[3], vertices[0]);  // Distancia entre v3 y v0
    return (d1 == d3 && d2 == d4);  // Las aristas opuestas deben ser iguales
}

// Constructor por defecto
Rectangle::Rectangle() : Shape(), vs(new Point2D[N_VERTICES]{Point2D(-1, 0.5), Point2D(1, 0.5), Point2D(1, -0.5), Point2D(-1, -0.5)}) {}

// Constructor con vértices y color
Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color) {
    if (!check(vertices)) {
        throw std::invalid_argument("The given vertices do not form a valid rectangle.");
    }
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = vertices[i];
    }
}

// Constructor de copia
Rectangle::Rectangle(const Rectangle &r) : Shape(r), vs(new Point2D[N_VERTICES]) {
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = r.vs[i];
    }
}

// Destructor
Rectangle::~Rectangle() {
    delete[] vs;
}

// Obtiene el vértice en la posición ind
Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= N_VERTICES) {
        throw std::out_of_range("Index out of range");
    }
    return vs[ind];
}

// Sobrecarga del operador []
Point2D Rectangle::operator[](int ind) const {
    return get_vertex(ind);
}

// Establece los vértices del rectángulo
void Rectangle::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("The given vertices do not form a valid rectangle.");
    }
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = vertices[i];
    }
}

// Sobrecarga del operador de asignación
Rectangle& Rectangle::operator=(const Rectangle &r) {
    if (this == &r) {
        return *this;
    }
    Shape::operator=(r);  // Asignación de la clase base
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = r.vs[i];
    }
    return *this;
}

// Implementación de los métodos heredados de Shape
double Rectangle::area() const {
    double width = Point2D::distance(vs[0], vs[1]);
    double height = Point2D::distance(vs[1], vs[2]);
    return width * height;
}

double Rectangle::perimeter() const {
    double width = Point2D::distance(vs[0], vs[1]);
    double height = Point2D::distance(vs[1], vs[2]);
    return 2 * (width + height);
}

void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = Point2D(vs[i].getX() + incX, vs[i].getY() + incY);
    }
}

// Imprime la información del rectángulo
void Rectangle::print() const {
    std::cout << "Rectangle [Color: " << get_color() << ", Vertices: ";
    for (int i = 0; i < N_VERTICES; ++i) {
        std::cout << vs[i] << " ";
    }
    std::cout << "]" << std::endl;
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream &out, const Rectangle &r) {
    out << "Rectangle [Color: " << r.get_color() << ", Vertices: ";
    for (int i = 0; i < Rectangle::N_VERTICES; ++i) {
        out << r.vs[i] << " ";
    }
    out << "]";
    return out;
}

