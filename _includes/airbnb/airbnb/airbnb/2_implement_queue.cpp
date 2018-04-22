//
//  2_implement_queue.cpp
//  airbnb
//
//  Created by Zhang, Mingda on 4/22/18.
//  Copyright © 2018 Zhang, Mingda. All rights reserved.
//

#include <iostream>
#include "Test.hpp"

using namespace std;
struct ListNode{
    int* A;
    ListNode* next;
    ListNode(int size){
        A = new int[size];
        next = NULL;
    }
    ~ListNode(){
        delete []A;
    }
};

class MyQueue{
public:
    MyQueue(int size){
        limit = size;
        head = new ListNode(size);
        tail = head;
        h_idx = 0;
        t_idx = 0;
        _size = 0;
    }
    
    int size(){
        return _size;
    }
    
    int pop(){
        if(empty())
            throw 0;
        if(head==NULL)
            throw 1;
        if(h_idx==limit){
            throw 2;
        }
        int ret = head->A[h_idx++];
        if(h_idx==limit){
            h_idx = 0;
            if(head->next==NULL){
                t_idx=0;
            }
            else{
                ListNode* tmp = head;
                head = head->next;
                delete tmp;
            }
        }
        _size--;
        return ret;
    }
    
    void push(int num){
        if(tail==NULL)
            throw 1;
        if(t_idx==limit){
            throw 2;
        }
        tail->A[t_idx++] = num;
        if(t_idx==limit){
            t_idx = 0;
            tail->next = new ListNode(limit);
            tail = tail->next;
        }
        _size++;
    }
    
    bool empty(){
        return head==tail && h_idx==t_idx;
    }
private:
    ListNode* head;
    ListNode* tail;
    int h_idx;
    int t_idx;
    int limit;
    int _size;
};

class MyQueueTest: public Test{
public:
    void test(){
        cout<<"2.implement queue"<<endl;
        MyQueue Q(2);
        cout<<"test empty:"<<Q.empty()<<endl;
        cout<<"test push 1:"<<endl;Q.push(1);
        cout<<"test empty:"<<Q.empty()<<endl;
        cout<<"test push 2:"<<endl;Q.push(2);
        cout<<"test empty:"<<Q.empty()<<endl;
        cout<<"test push 3:"<<endl;Q.push(3);
        cout<<"test empty:"<<Q.empty()<<endl;
        cout<<"test pop 1:"<<Q.pop()<<endl;
        cout<<"test empty:"<<Q.empty()<<endl;
        cout<<"test pop 2:"<<Q.pop()<<endl;
        cout<<"test empty:"<<Q.empty()<<endl;
        cout<<"test push 4:"<<endl;Q.push(4);
        cout<<"test empty:"<<Q.empty()<<endl;
        cout<<"test pop 3:"<<Q.pop()<<endl;
        cout<<"test empty:"<<Q.empty()<<endl;
        cout<<"test pop 3:"<<Q.pop()<<endl;
        cout<<"test empty:"<<Q.empty()<<endl;
        try {
            cout<<"test throw error:"<<Q.pop()<<"did not work"<<endl;
        }
        catch(int e){
            cout<<"throw "<<e<<endl;
        }
        cout<<"=============================="<<endl;
    }
};
