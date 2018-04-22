//
//  main.cpp
//  airbnb
//
//  Created by Zhang, Mingda on 4/21/18.
//  Copyright © 2018 Zhang, Mingda. All rights reserved.
//

#include <iostream>
#include "1_collatz_conjection.cpp"
#include "2_implement_queue.cpp"
#include "3_list_list.cpp"
using namespace std;

int main(){
    Test* test = new ConjectureTest();
    test->test();
    delete test;
    test = new MyQueueTest();
    test->test();
    delete test;
    test = new SolutionTest();
    test->test();
    return 0;
}
