#include "shape.h"
#include "new_shape.h"
#include "rhombus.h"

class RhombusAdapter : public Shape {
    Rhombus* rhombus;
public:
    RhombusAdapter() { rhombus = new Rhombus() ; }
    void draw() {
        rhombus->drawShape();
    }
    void resize() {
        std::cout << "Rhombus object can't be resized. Please create new one with required values." << std::endl;
    }
    std::string description() {
        return rhombus->description();
    }
    ~RhombusAdapter() { delete rhombus; }
};