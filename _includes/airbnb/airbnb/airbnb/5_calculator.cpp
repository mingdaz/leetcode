//
//  calculator.cpp
//  airbnb
//
//  Created by Zhang, Mingda on 4/22/18.
//  Copyright © 2018 Zhang, Mingda. All rights reserved.
//

#include <iostream>
#include <stack>
#include "Test.hpp"
using namespace std;

class Calculator{
public:
    struct node{
        int val = 0;
        int sign = 1;
        node(int val,int sign):val(val),sign(sign){}
    };
    int calculate(string s) {
        stack<node*> S;
        int idx = 0;
        S.push(new node(0,1));
        while(idx<s.size()){
            while(s[idx]==' ') idx ++;
            if(s[idx]=='('){
                S.push(new node(0,1));
            }
            else if(s[idx]==')'){
                node* p = S.top();
                S.pop();
                S.top()->val += (S.top()->sign>0?p->val:-p->val);
                delete p;
            }
            else if(s[idx]=='+'){
                S.top()->sign = 1;
            }
            else if(s[idx]=='-'){
                S.top()->sign = -1;
            }
            else{
                int num = 0;
                while(isdigit(s[idx])){
                    num = num*10 + s[idx] - '0';
                    idx ++;
                }
                S.top()->val += (S.top()->sign>0?num:-num);
                idx--;
            }
            idx++;
        }
        return S.top()->val;
    }
};

class CalculatorTest: public Test{
    void test(){
        cout<<"5.calculator"<<endl;
        Calculator c;
        cout<<c.calculate("1 + 1")<<endl;
        printsep();
    }
};
