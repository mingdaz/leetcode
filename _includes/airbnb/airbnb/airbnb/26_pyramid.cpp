//
//  26_pyramid.cpp
//  airbnb
//
//  Created by Zhang, Mingda on 5/2/18.
//  Copyright © 2018 Zhang, Mingda. All rights reserved.
//
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "Test.hpp"
using namespace std;

class Pyramid {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,unordered_set<char>> dict;
        unordered_map<char,unordered_set<char>> bt;
        for(int i=0;i<allowed.size();i++){
            bt[allowed[i][0]].insert(allowed[i][1]);
            dict[allowed[i].substr(0,2)].insert(allowed[i][2]);
        }
        return helper(bottom,dict,bt);
    }
private:
    void generate_next(vector<string>& res,string& bottom, string& path, unordered_map<string,unordered_set<char>>& dict,unordered_map<char,unordered_set<char>> bt){
        if(path.size()+1==bottom.size()){
            res.push_back(path);
            return;
        }
        int i= path.size();
        char a= bottom[i];
        if(bt.count(a)==0) return;
        for(auto it = bt[a].begin();it!=bt[a].end();++it){
            string key = "";
            char b = *it;
            key.push_back(a);
            key.push_back(b);
            if(dict.count(key)==0) continue;
            for(auto it2 = dict[key].begin();it2!=dict[key].end();++it2){
                path.push_back(*it2);
                generate_next(res,bottom,path,dict,bt);
                path.pop_back();
            }
        }
    }
    bool helper(string& bottom, unordered_map<string,unordered_set<char>>& dict,unordered_map<char,unordered_set<char>> bt){
        std::cout<<bottom<<endl;
        if(bottom.size()==1) return true;
        vector<string> next;
        string path = "";
        generate_next(next,bottom,path,dict,bt);
        for(int i=0;i<next.size();i++){
            if(helper(next[i],dict,bt))
                return true;
        }
        return false;
        
    }
};

class PyramidTest: public Test {
public:
    void test(){
        cout<<"26. Pyramid"<<endl;
        Pyramid Py;
        string bottom = "AABA";
        vector<string> allowed = {"AAA","AAB","ABA","ABB","BAC"};
        cout<<Py.pyramidTransition(bottom, allowed);
        printsep();
    }
};

