//
//  10_ip2cidr.cpp
//  airbnb
//
//  Created by Zhang, Mingda on 4/25/18.
//  Copyright © 2018 Zhang, Mingda. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "Test.hpp"
using namespace std;

class ip2cidr {
public:
    vector<string> ipToCIDR(string ip, int n) {
        unsigned int start_ip = ip2int(ip);
        vector<string> ret;
        while(n>0){
            int p = 1;
            int cnt = 0;
            while(p<=n&&(p&start_ip)==0){
                p<<=1;
                cnt++;
            }
            if(p>n){
                p>>=1;
                cnt--;
            }
            cnt = 32 - cnt;
            ret.push_back(int2ip(start_ip)+"/"+to_string(cnt));
            n -= p;
            start_ip += p;
        }
        return ret;
    }
private:
    unsigned int ip2int(string& ip){
        unsigned int num = 0;
        unsigned int res = 0;
        for(int i=0;i<ip.size();i++){
            if(ip[i]=='.'){
                res |= num;
                res <<= 8;
                num=0;
            }
            else{
                num = num*10 + ip[i] - '0';
            }
        }
        res|=num;
        return res;
    }
    string int2ip(unsigned int num){
        return to_string((num>>24) & 0xFF) + "."
        + to_string(num>>16 & 0xFF) + "."
        + to_string(num>>8 & 0xFF) + "."
        + to_string(num & 0xFF);
    }
};

class ip2cidrTest: public Test {
public:
    void test(){
        cout<<"10. ip to cidr"<<endl;
        ip2cidr P;
        vector<string> res= P.ipToCIDR("255.0.0.7", 10);
        for(auto str:res){
            cout<<str<<endl;
        }
        printsep();
    }

};
