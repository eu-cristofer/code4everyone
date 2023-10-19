#include <iostream>
#include <cmath>

class Point {
private:
    double x, y, z;

public:
    // Constructors
    Point(double _x = 0.0, double _y = 0.0, double _z = 0.0) : x(_x), y(_y), z(_z) {}

    // Getters and Setters
    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }
    void setX(double _x) { x = _x; }
    void setY(double _y) { y = _y; }
    void setZ(double _z) { z = _z; }

    /*
        Vector operations:
    */
    double magnitude() const {
        if (z == 0)
            return std::sqrt(x * x + y * y);
        return std::sqrt(x * x + y * y + z * z);
    }

    Point normalize() const {
        if (z == 0) {
            double mag = magnitude();
            if (mag == 0)
                return Point(0, 0);
            return Point(x / mag, y / mag);
        } else {
            double mag = magnitude();
            if (mag == 0)
                return Point(0, 0, 0);
            return Point(x / mag, y / mag, z / mag);
        }
    }

    // Scalar multiplication
    Point operator*(double scalar) const {
        if (z == 0)
            return Point(x * scalar, y * scalar);
        return Point(x * scalar, y * scalar, z * scalar);
    }

    // Vector addition
    Point operator+(const Point& other) const {
        if (z == 0 && other.getZ() == 0)
            return Point(x + other.getX(), y + other.getY());
        return Point(x + other.getX(), y + other.getY(), z + other.getZ());
    }

    // Vector subtraction
    Point operator-(const Point& other) const {
        if (z == 0 && other.getZ() == 0)
            return Point(x - other.getX(), y - other.getY());
        return Point(x - other.getX(), y - other.getY(), z - other.getZ());
    }

    // Dot product
    double dot(const Point& other) const {
        if (z == 0 && other.getZ() == 0)
            return x * other.getX() + y * other.getY();
        return x * other.getX() + y * other.getY() + z * other.getZ();
    }

    // Cross product (only applicable for 3D vectors)
    Point cross(const Point& other) const {
        if (z == 0 || other.getZ() == 0) {
            std::cerr << "Cross product is only applicable for 3D vectors." << std::endl;
            return Point();
        }
        return Point(y * other.getZ() - z * other.getY(), z * other.getX() - x * other.getZ(), x * other.getY() - y * other.getX());
    }

    // Output the vector
    void print() const {
        if (z == 0) {
            std::cout << "(" << x << ", " << y << ")";
        } else {
            std::cout << "(" << x << ", " << y << ", " << z << ")";
        }
    }

    // Overload double
    operator double() const {return this->magnitude();}
};

int main() {
    double d;
    Point vector2D(3.0, 4.0);
    Point vector3D(1.0, 2.0, 3.0);

    std::cout << "2D Vector: ";
    vector2D.print();
    d = vector2D;
    std::cout << std::endl << "Magnitude: " << d << std::endl;
    std::cout << std::endl;

    std::cout << "3D Vector: ";
    vector3D.print();
    std::cout << std::endl;

    Point sum = vector2D + vector3D;
    std::cout << "Sum of vectors: ";
    sum.print();
    std::cout << std::endl;

    double dotProduct = vector2D.dot(vector3D);
    std::cout << "Dot product of vectors: " << dotProduct << std::endl;

    Point crossProduct = vector2D.cross(vector3D);
    std::cout << "Cross product of vectors: ";
    crossProduct.print();
    std::cout << std::endl;

    return 0;
}
