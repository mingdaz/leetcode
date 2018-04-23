//
//  collatz_conjection.cpp
//  airbnb
//
//  Created by Zhang, Mingda on 4/21/18.
//  Copyright © 2018 Zhang, Mingda. All rights reserved.
//
#include <unordered_map>
#include <iostream>
#include "Test.hpp"
using namespace std;
class Conjecture{
public:
    int findLongestSteps(int num){
        int ret = 0;
        for(int i=1;i<=num;i++){
            int tmp = findSteps(i);
            if(tmp>ret) ret = tmp;
        }
        return ret;
    }
    
private:
    int findSteps(int num){
        if(num<=1) return 1;
        if(hm.find(num)!=hm.end()){
            return hm[num];
        }
        if((num&1)==0) return 1 + findSteps(num>>1);
        return 1 + findSteps(num*3+1);
    }
    unordered_map<int,int> hm;
};

class ConjectureTest: public Test{
public:
    void test(){
        cout<<"1.collatz_conjecture"<<endl;
        Conjecture c;
        cout<<c.findLongestSteps(7)<<"=="<<17<<endl;
        printsep();
    }
};
