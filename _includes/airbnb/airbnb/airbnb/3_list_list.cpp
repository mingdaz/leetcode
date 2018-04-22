	//
//  3_list_list.cpp
//  airbnb
//
//  Created by Zhang, Mingda on 4/22/18.
//  Copyright © 2018 Zhang, Mingda. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include "Test.hpp"

using namespace std;

class NestedInteger {
public:
    NestedInteger(int num){
        isint = true;
        a = num;
    }
    NestedInteger(vector<NestedInteger>& num){
        isint = false;
        b = num;
    }
    bool isInteger() const{
        return isint;
    }
    int getInteger() const{
        return a;
    }
    const vector<NestedInteger> &getList() const{
        return b;
    }
private:
    bool isint;
    int a;
    vector<NestedInteger> b;
};

typedef vector<NestedInteger>::iterator NII;
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        head = nestedList.begin();
        tail = nestedList.end();
        move();
    }
    
    int next() {
        int res = head->getInteger();
        head++;
        move();
        return res;
    }
    
    bool hasNext() {
        return !S.empty()||head!=tail;
    }
private:
    void move(){
        if(head!=tail){
            while(head!=tail&&!head->isInteger()){
                auto newlist = head->getList();
                auto th = newlist.begin();
                auto tt = newlist.end();
                head++;
                if(head!=tail)
                    S.push(pair<NII,NII>(head,tail));
                head = th;
                tail = tt;
            }
        }
        while(head==tail&&!S.empty()){
            auto p = S.top();
            S.pop();
            head = p.first;
            tail = p.second;
        }
    }
    NII head,tail;
    stack<pair<NII,NII>> S;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

class SolutionTest: public Test{
public:
    void test(){
        vector<NestedInteger> a;
        vector<NestedInteger> b(2,NestedInteger(1));
        a.push_back(NestedInteger(b));
        a.push_back(NestedInteger(2));
        a.push_back(NestedInteger(b));
        NestedIterator testcase(a);
        while(testcase.hasNext())
            cout<<testcase.next()<<",";
    }
};
