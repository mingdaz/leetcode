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
#include "5_calculator.cpp"
#include "6_travel_buddy.cpp"
#include "7_file_system.cpp"
#include "8_palindrome_pairs.cpp"
#include "9_Find_median.cpp"
#include "10_ip2cidr.cpp"
#include "12_text_justification.cpp"
#include "13_regex.cpp"
#include "15_hilbert_curve.cpp"
#include "18_round_price.cpp"
#include "25_minimum_cost_k_stop.cpp"
#include "26_pyramid.cpp"

using namespace std;

int main(){
    Test* test = new ConjectureTest();
    test->test();
    delete test;
    test = new MyQueueTest();
    test->test();
    delete test;
    test = new Vector2DTest();
    test->test();
    delete test;
    test = new CalculatorTest();
    test->test();
    delete test;
    test = new TravelBuddyTest();
    test->test();
    delete test;
    test = new FileSystemTest();
    test->test();
    delete test;
    test = new PalindromeTest();
    test->test();
    delete test;
    test = new FindMedianTest();
    test->test();
    delete test;
    test = new ip2cidrTest();
    test->test();
    delete test;
    test = new TextJustificationTest();
    test->test();
    delete test;
    test = new RegexTest();
    test->test();
    delete test;
    test = new HilbertTest();
    test->test();
    delete test;
    test = new RoundPriceTest();
    test->test();
    delete test;
    test = new PyramidTest();
    test->test();
    return 0;
}
