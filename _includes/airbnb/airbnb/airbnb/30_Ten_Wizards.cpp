//
//  30_Ten_Wizards.cpp
//  airbnb
//
//  Created by Zhang, Mingda on 5/5/18.
//  Copyright © 2018 Zhang, Mingda. All rights reserved.
//

#include <queue>
#include <vector>
#include <unordered_set>
#include <iostream>
#include "Test.hpp"
using namespace std;

class Wizard{
public:
    vector<int> solve(vector<vector<int>> E){
        vector<int> parent(10,-1);
        vector<vector<int>> G(10,vector<int>(10,-1));
        vector<int> dist(10,INT_MAX);
        dist[0] = 0;
        for(int i=0;i<10;i++){
            for(int j:E[i]){
                int tmp = (i - j)*(i-j);
                G[i][j] = tmp;
                G[j][i] = tmp;
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int, int>>> pq;
        pq.push(pair<int,int>(0,0));
        while(pq.size()){
            auto p = pq.top();
            pq.pop();
            int i = p.second;
//            if(i==9) break;
            for(int j = 0;j<10;j++){
                if(G[i][j]>0&&dist[j]>dist[i]+G[i][j]){
                    parent[j] = i;
                    dist[j] =dist[i] + G[i][j];
                    pq.push(pair<int,int>(dist[j],j));
                }
            }
        }
        vector<int> res;
        int i = 9;
        while(i!=0){
            res.push_back(i);
            i = parent[i];
        }
        res.push_back(0);
        reverse(res.begin(), res.end());
        return res;
    }
};

class WizardTest: public Test {
public:
    void test(){
        cout<<"30. Ten Wizard"<<endl;
        Wizard W;
        vector<int> res1 = W.solve({{1},{2,5},{9},{},{},{9},{},{},{},{}});
        for(int i:res1){
            cout<<i<<",";
        }
        cout<<endl;
        printsep();
    }
    
};
