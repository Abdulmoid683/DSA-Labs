#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() = 0;  
};
 
class Circle : public Shape {
private:
    double radius;

public:
  
    Circle(double r) {
        radius = r;
    }

    double area() override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
  
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double area() override {
        return length * width;
    }
};

int main() {

    Circle circle(5);

    Rectangle rectangle(10, 4);

    cout << "===== Shape Areas =====" << endl;

    cout << "Area of Circle: "
        << circle.area() << endl;

    cout << "Area of Rectangle: "
        << rectangle.area() << endl;

    return 0;
}