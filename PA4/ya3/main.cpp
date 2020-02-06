#include "node.h"
#include "operator.h"
#include "var.h"
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <map>
#include <vector>
using namespace std;

// extern seq;

// void set_seq() {
//     seq["=="] = 1;
//     seq["<="] = 1;
//     seq[">="] = 1;
//     seq["<"] = 1;
//     seq[">"] = 1;
//     seq["!="] = 1;

//     seq["not"] = 2;
//     seq["and"] = 3;
//     seq["or"] = 4;

//     seq["="] = 5;
//     seq["print"] = 6;
// }

std::map<string, Var*> var;

bool isopt(string& t ) {
    if (t == ">" && t == "<" && t == "==" && t == "<=" && t == ">=" && t == "and" && t == "or" && t == "!=") {
        return true;
    }
    return false;
}

void parses(std::vector<string>& m) {
    stack <string> opts;
    stack <int> vals;
    
    for (int i = 0; i < m.size(); ++i) {

        if (!isdigit(m[i][0])) {
            vals.push(new Var(atoi(m[i].data())));
        } else if (isopt(m[i])) { 
            int prev_pri = Operator::priority(opts.top());
            for ( ; !opts.empty() && Operator::priority(m[i]) > Operator::priority(opts.top()); ) {
                string temp = opts.top();
                opts.pop();
                Node* node1 = vals.top();
                vals.pop();
                Node* node2 = vals.top();

                if (temp == "==") {
                    vals.push( new DEQ );
                }
                else if (temp == ">" ) vals.push( new GT(node1, node2));
                else if (temp == "<" ) vals.push( new ST(temp));
                else if (temp == ">=" ) vals.push( new GTE(temp));
                else if (temp == "<=" ) vals.push( new STE(temp));
                else if (temp == "!=" ) vals.push( new NEQ(temp));
                else if (temp == "not" ) vals.push( new NOT(temp));
                else if (temp == "and" ) vals.push( new AND(temp));
                else if (temp == "or" ) vals.push( new OR(temp));
                else if (temp == "=" ) vals.push( new EQ(temp));
                else if (temp == "print" ) vals.push( new PRINT(temp));

            }

            

        } else {
            if (!var.count(m[i])) {
                var[m[i]] = new Var(0);
            } else {
                //...
            }
        }
    }
}


int main() {
    string line;
    
    while (getline(cin, line)) {
        stringstream input;
        input << line;
    }
    
    return 0;
}