#pragma once

class Expression {
private:
    stringstream& input;

public:
    Expression(const stringstream& s) : input(s) {}
};
