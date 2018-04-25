//
//  7_file_system.cpp
//  airbnb
//
//  Created by Zhang, Mingda on 4/23/18.
//  Copyright © 2018 Zhang, Mingda. All rights reserved.
//
#include <unordered_map>
#include <string>
#include <iostream>
#include "Test.hpp"
using namespace std;

struct PathNode{
    int val;
    unordered_map<string,PathNode*> children;
    PathNode(int val):val(val){}
};

class FileSystem{
public:
    FileSystem(){
        root = new PathNode(0);
    }
    bool create(string s,int val){
        PathNode* cur = root;
        size_t i= s.find('/')+1;
        while(i<s.size()){
            size_t next = s.find('/',i);
            if(next==string::npos){
                next = s.size();
                string folder = s.substr(i,next - i);
                if(cur->children.count(folder)==0){
                    cur->children[folder] = new PathNode(val);
                }
            }
            else{
                string folder = s.substr(i,next - i);
                if(cur->children.count(folder)==0){
                    return false;
                }
                cur = cur->children[folder];
            }
            i = next + 1;
        }
        return true;
    }
    int get(string s){
        PathNode* cur = root;
        size_t i= s.find('/')+1;
        while(i<s.size()){
            size_t next = s.find('/',i);
            if(next==string::npos){
                next = s.size();
            }
            string folder = s.substr(i,next - i);
            if(cur->children.count(folder)==0){
                throw 1;
            }
            cur = cur->children[folder];
            i = next + 1;
        }
        return cur->val;
    }
    bool set(string s,int val){
        PathNode* cur = root;
        size_t i= s.find('/')+1;
        while(i<s.size()){
            size_t next = s.find('/',i);
            if(next==string::npos){
                next = s.size();
            }
            string folder = s.substr(i,next - i);
            if(cur->children.count(folder)==0){
                return false;
            }
            cur = cur->children[folder];
            i = next + 1;
        }
        cur->val = val;
        return true;
    }
private:
    PathNode* root;
};

class FileSystemTest: public Test{
public:
    void test(){
        cout<<"7. File System"<<endl;
        FileSystem F;
        cout<<"create /a:"<<F.create("/a",1)<<endl;
        cout<<"get /a:"<<F.get("/a")<<endl;
        cout<<"create /a/b:"<< F.create("/a/b", 2)<<endl;
        cout<<"get /a/b:"<< F.get("/a/b")<<endl;
        cout<<"set /a/b:"<< F.set("/a/b", 3)<<endl;
        cout<<"get /a/b:"<< F.get("/a/b")<<endl;
        cout<<"create /c/d:"<<F.create("/c/d", 1)<<endl;
        try{
            F.get("/c");
        }
        catch(int e){
            cout<<"error code:"<<e<<endl;
        }
        printsep();
    }
};
