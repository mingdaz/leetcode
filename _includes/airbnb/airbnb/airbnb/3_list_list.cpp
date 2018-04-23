	//
//  3_list_list.cpp
//  airbnb
//
//  Created by Zhang, Mingda on 4/22/18.
//  Copyright © 2018 Zhang, Mingda. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Test.hpp"

using namespace std;

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        head = vec2d.begin();
        tail = vec2d.end();
        if(head!=tail){
            cur = (*head).begin();
            move();
        }
        hasprev = false;
    }
    
    int next() {
        hasprev = true;
        pre_col = cur;
        pre_row = head;
        int ret = *cur;
        cur++;
        move();
        return ret;
    }
    
    bool hasNext() {
        return head!=tail;
    }
    
    void remove(){
        pre_row->erase(pre_col);
    }
    
private:
    void move(){
        while(head!=tail&&cur==head->end() ){
            head++;
            cur = head->begin();
        }
    }
    vector<vector<int>>::iterator head,tail,pre_row;
    vector<int>::iterator cur,pre_col;
    bool hasprev;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */

class Vector2DTest: public Test{
public:
    void test(){
        cout<<"3.list_list"<<endl;
        vector<vector<int>> a = {{1,2,3},{4,5},{6,7,8}};
        Vector2D vd(a);
        for(int i=0;i<5;i++){
            cout<<vd.next()<<",";
        }
        vd.remove();
        while(vd.hasNext())
            cout<<vd.next()<<",";
        cout<<endl;
        cout<<"print origin"<<endl;
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[i].size();j++){
                cout<<a[i][j]<<",";
            }
        }
        cout<<endl;
        printsep();
    }
};
