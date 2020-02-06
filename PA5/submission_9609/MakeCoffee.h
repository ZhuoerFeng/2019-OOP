//
//  MakeCoffee.h
//  t2
//
//  Created by Fan Qu on 2018/5/23.
//  Copyright © 2018年 GF. All rights reserved.
//

#ifndef MakeCoffee_h
#define MakeCoffee_h

#include "Cup.h"
#include "AbstractCoffee.h"

class MakeCoffee {
public:
    virtual AbstractCoffee* makeCoffee(const string& type, Cup *cup) = 0;
};

#endif /* MakeCoffee_h */
