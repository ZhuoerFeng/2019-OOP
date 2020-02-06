#include "shape.h"
#include "new_shape.h"

#include "triangle.h"

class TriangleAdapter : public Shape {
    Triangle* triangle;
public:
    TriangleAdapter() { triangle = new Triangle(); }
    void draw() {
        triangle->drawShape();
    }
    void resize() {
        std::cout << "Triangle object can't be resized. Please create new one with required values." << std::endl;
    }
    std::string description() {
        return triangle->description();
    }
    ~TriangleAdapter() { delete triangle; }
};

