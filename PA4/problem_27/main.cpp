#include <map>
#include <stack>
#include <string>
#include <iostream>
#include <sstream>

#include "node.h"
#include "operator.h"

using std::map;
using std::string;
using std::stack;
using std::stringstream;

map<string, Node*> var;
map<string, Operator*> op;

void init() {
    op[">"] = new GT();
    op["<"] = new ST();
    op[">="] = new GTE();
    op["<="] = new STE();
    op["=="] = new DEQ();
    op["!="] = new NEQ();
    op["not"] = new NOT();
    op["and"] = new AND();
    op["or"] = new OR();
}

void parse(stringstream& input) {
    stack<Operator*> opts;
    stack<Node*> h;
    
    string target, t;
    bool should_print = false;

    input >> t;
    if (t == "print") {
        should_print = true;
    } else {
        target = t;
        input >> t;
    }

    while (input >> t) {
        if (t[0] >= '0' && t[0] <= '9') {
            h.push(new Node(stoi(t), INT));
        } else if (t == "True" || t == "False") {
            h.push(new Node(t == "True", BOOL));
        } else if (op.count(t)) {
            auto* cur = op[t];
            while (!opts.empty() && opts.top()->priority() <= cur->priority()) {
                opts.top()->calc(h);
                opts.pop();
            }
            opts.push(cur);
        } else {
            h.push(var[t]);
        }
    }

    while (!opts.empty()) {
        opts.top()->calc(h);
        opts.pop();
    }
    
    if (should_print) {
        auto* a = h.top();
        a->print();
    } else {
        var[target] = h.top();
    }
}


int main() {
    init();
    string line;
    
    while (getline(std::cin, line)) {
        stringstream input;
        input << line;
        parse(input);
    }
    return 0;
}