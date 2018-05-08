//
//  29_minimum.cpp
//  airbnb
//
//  Created by Zhang, Mingda on 5/5/18.
//  Copyright © 2018 Zhang, Mingda. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include "Test.hpp"

using namespace std;

class Minimum {
public:
    vector<int> find(vector<vector<int>>& edges, int n){
        vector<unordered_set<int>> G;
        G.resize(n);
        for(int i=0;i<edges.size();i++){
            G[edges[i][0]].insert(edges[i][1]);
        }
        unordered_set<int> visit, res,visit2;
        for(int i=0;i<n;i++){
            if(visit.count(i)==0){
                res.insert(i);
                visit.insert(i);
                visit2.clear();
                search(res,G,i,i,visit,visit2);
            }
            
        }
        vector<int> res2;
        for(int i:res){
            res2.push_back(i);
        }
        return res2;
    }
private:
    void search(unordered_set<int>& res, vector<unordered_set<int>>& G, int cur, int start, unordered_set<int>& visit, unordered_set<int>& curvisit){
        curvisit.insert(cur);
        visit.insert(cur);
        for(int next:G[cur]){
            if(res.count(next)&&next!=start){
                res.erase(next);
            }
            if(curvisit.count(next)==0){
                search(res, G, next, start, visit, curvisit);
            }
        }
    }
};

class MinimumTest: public Test{
public:
    void test(){
        cout<<"29 minimum vertices"<<endl;
        Minimum M;
        vector<vector<int>> t1 = {{2,9},{3,3},{3,5},{3,7},{4,8},{5,8},{6,6},{7,4},{8,7},{9,3},{9,6}};
        vector<int> res = M.find(t1, 10);
        for(int i:res)
            cout<<i<<",";
        cout<<endl;
        
        vector<vector<int>> t2 = {{0,1},{1,2},{2,0},{3,1}};
        vector<int> res2 = M.find(t2, 4);
        for(int i:res2)
            cout<<i<<",";
        cout<<endl;
        
        printsep();
    }
};
