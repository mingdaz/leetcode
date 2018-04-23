//
//  TestFrame.cpp
//  airbnb
//
//  Created by Zhang, Mingda on 4/22/18.
//  Copyright © 2018 Zhang, Mingda. All rights reserved.
//

#ifndef TEST_HPP
#define TEST_HPP
#include <iostream>
using namespace std;

class Test{
public:
    virtual void test(){}
    void printsep(){
        cout<<"=============================="<<endl;
    }
};
#endif
