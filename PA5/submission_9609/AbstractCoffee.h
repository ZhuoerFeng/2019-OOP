//
//  AbstractCoffee.h
//  t2
//
//  Created by Fan Qu on 2018/5/23.
//  Copyright © 2018年 GF. All rights reserved.
//

#ifndef AbstractCoffee_h
#define AbstractCoffee_h
                                        
class AbstractCoffee {
protected:
    Cup *cup;
    string name;
    
public:
    
    virtual ~AbstractCoffee() {}
    
    virtual void drink() = 0;
    
    AbstractCoffee(): cup(nullptr) { }
    AbstractCoffee(const string& name, Cup* const cup): cup(cup), name(name) { }
};


  
    


#endif /* AbstractCoffee_h */
