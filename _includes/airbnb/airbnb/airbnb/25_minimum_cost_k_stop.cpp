//
//  25_minimum_cost_k_stop.cpp
//  airbnb
//
//  Created by Zhang, Mingda on 5/1/18.
//  Copyright © 2018 Zhang, Mingda. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include "Test.hpp"
using namespace std;

class Kstop {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<unordered_map<int,int>> G;
        G.resize(n);
        for(int i = 0;i<flights.size();i++){
            G[flights[i][0]][flights[i][1]] = flights[i][2];
        }
        queue<int> Q;
        Q.push(src);
        int* res = new int[n];
        int* prev = new int[n];
        for(int i=0;i<n;i++){
            prev[i] = INT_MAX;
            res[i] = INT_MAX;
        }
        prev[src] = 0;
        bool* visit = new bool[n];
        for(int i=0;i<=K;i++){
            int lens = Q.size();
            memset(visit,0,sizeof(bool)*n);
            for(int j=0;j<lens;j++){
                int p = Q.front();
                Q.pop();
                for(auto it = G[p].begin();it!=G[p].end();++it){
                    int q = it->first;
                    if(q==src) continue;
                    cout<<p<<","<<it->first<<","<<it->second<<"::::"<<q<<",";
                    res[q] = min(prev[q],prev[p]+it->second);
                    cout<<res[q]<<endl;
                    if(!visit[q]){
                        Q.push(q);
                        visit[q] = true;
                    }
                }
            }
            int* tmp = prev;
            prev = res;
            res = tmp;
        }
        return prev[dst]==INT_MAX?-1:prev[dst];
    }
};

class KstopTest: public Test{
public:
    void test(){
        
        Kstop k;
        vector<vector<int>> flight =
        {{0,1,5},{1,2,5},{0,3,2},{3,1,2},{1,4,1},{4,2,1}};
        cout<<k.findCheapestPrice(5, flight, 0, 2, 2);
    }
    
};
