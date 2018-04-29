//
//  18_round_price.cpp
//  airbnb
//
//  Created by Zhang, Mingda on 4/28/18.
//  Copyright © 2018 Zhang, Mingda. All rights reserved.
//
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include "Test.hpp"
using namespace std;

#define PFI pair<float,int>
struct compare{
    bool operator()(const PFI& l,const PFI& r) const{
        return l.first > r.first;
    }
    
};

class RoundPrice{
public:
    vector<int> calculate(vector<float> prices){
        priority_queue<PFI,vector<PFI>,compare> pq;
        vector<int> res;
        res.resize(prices.size());
        int isum = 0;
        float fsum = 0;
        for(int i=0;i<prices.size();i++){
            res[i] = int(prices[i]);
            isum += res[i];
            fsum += prices[i];
            pq.push(PFI(res[i] + 1 - prices[i],i));
        }
        int sum = round(fsum);
        for(int i=0;i<sum - isum;i++){
            auto p = pq.top();
            pq.pop();
            res[p.second]++;
        }
        return res;
    }
};

class RoundPriceTest : public Test {
public:
    void test(){
        cout<<"18 Round Price"<<endl;
        RoundPrice R;
        for(auto p:R.calculate({1.2,2.3,3.4}))
            cout<<p<<",";
        cout<<endl;
        for(auto p:R.calculate({1.2,2.5,3.6,4}))
            cout<<p<<",";
        cout<<endl;
        printsep();
    }
};
