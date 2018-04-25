//
//  6_travel_buddy.cpp
//  airbnb
//
//  Created by Zhang, Mingda on 4/23/18.
//  Copyright © 2018 Zhang, Mingda. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <queue>
#include "Test.hpp"
using namespace std;

class TravelBuddy{
public:
    vector<string> travelbuddy(vector<string> mylist, vector<vector<string>> others_list){
        unordered_set<string> myset(mylist.begin(),mylist.end());
        vector<string> ret;
        priority_queue<pair<int, string>> Q;
        for(size_t i=0;i<others_list.size();i++){
            int tmp = similarity(myset,others_list[i]);
            if(tmp>0)
                Q.push(pair<int,string>(tmp,others_list[i][0]));
        }
        while(Q.size()){
            auto p = Q.top();
            Q.pop();
            ret.push_back(p.second);
        }
        return ret;
    }
private:
    int similarity(unordered_set<string>& myset,vector<string>& buddy){
        int cnt = 0;
        for(size_t i=1;i<buddy.size();i++){
            if(myset.find(buddy[i])!=myset.end())
                cnt++;
        }
        if(cnt*2<myset.size())
            cnt = -1;
        return cnt;
    }
};

class TravelBuddyTest: public Test{
public:
    void test(){
        cout<<"6. TravelBuddy Test"<<endl;
        vector<string> mylist= {"a","b","c","d","e"};
        vector<vector<string>> others_lists = {
            {"1","0","0","0","d","e"},
            {"2","0","0","c","d","e"},
            {"3","0","0","c","d","e"},
            {"4","a","b","c","d","e"}
        };
        TravelBuddy b;
        vector<string> rank = b.travelbuddy(mylist, others_lists);
        cout<<"ranking [";
        for(auto str:rank){
            cout<<str<<",";
        }
        cout<<"],expecting:[4,3,2,]"<<endl;
        printsep();
    }
};
