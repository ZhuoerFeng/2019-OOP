代码架构说明：
    目前存在问题：继承自new_shape.h的两个类型triangle.h与rhombus.h不匹配drawing的接口。现在分别给它们设计相对应的adapter来实现“适配器”
    解决方案：
        1. 首先，对triangle和rhombus，它们有两个接口不适合shape的借口，resize()与description()。举triangle为例，设计TriangleAdapter()，它继承自shape类，将triangle作为成员进行使用调用，通过重载shape的虚函数实现了两个接口的适配。
        2. 在main.cpp具体使用过程中，main使用的便不再是triangle了，而是装有适配器的TriangleAdapter了。在shape的addShape过程中，TriangleAdapter通过向上类型转换成了shape，由于虚函数表各个接口仍然保留了TriangleAdapter的实现，从而解决了问题。
        3. 总结来看，代码架构为main.cpp调用（include）shape的rectangle和circle，以及装了“转接头”的TriangleAdapter和RhombusAdapter。转接头的样子，是继承自shape，以转接者adaptee为成员的类。其他的代码结构保留。
    修改之处：
        1. 新增TriangleAdapter与RhombusAdapter
        2. main.cpp 中所有的Triangle和Rhombus改为TriangleAdapter与RhombusAdapter