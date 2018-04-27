//
//  13_regex.cpp
//  airbnb
//
//  Created by Zhang, Mingda on 4/25/18.
//  Copyright © 2018 Zhang, Mingda. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Test.hpp"

using namespace std;

class Regex {
public:
    bool isMatch(string s, string p) {
        return helper(s,p,0,0);
    }
    bool helper(string& s,string& p,int i, int j){
        if(i==s.size()) return j==p.size();
        else if(j==p.size())
            return false;
        else if(s[i]==p[j]||p[j]=='?')
            return helper(s,p,i+1,j+1);
        else if(p[j]=='*')
            return helper(s,p,i,j+1)||helper(s,p,i+1,j)||helper(s,p,i+1,j+1);
        else
            return false;
    }
};

class RegexTest: public Test{
public:
    void test(){
        cout<<"13. regex"<<endl;
        Regex r;
        cout<<r.isMatch("aa","*")<<endl;
        printsep();
    }
};
