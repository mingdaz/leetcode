//
//  28_alien_dic.cpp
//  airbnb
//
//  Created by Zhang, Mingda on 5/4/18.
//  Copyright © 2018 Zhang, Mingda. All rights reserved.
//

#include <vector>
#include <string>
#include <iostream>
#include "Test.hpp"
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<bool> exist(26,false);
        vector<int> indegree(26,0);
        vector<vector<bool>> G(26,vector<bool>(26,false));
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                exist[words[i][j] - 'a'] = true;
            }
        }
        for(int i=1;i<words.size();i++){
            for(int j=0;j<min(words[i].size(),words[i-1].size());j++){
                if(words[i-1][j]!=words[i][j]){
                    G[words[i-1][j] - 'a'][words[i][j] - 'a'] = true;
                    break;
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<26;i++){
            if(exist[i]){
                cnt++;
                for(int j=0;j<26;j++){
                    if(G[i][j])
                        indegree[j]++;
                }
            }
        }
        string res;
        bool flag = true;
        while(cnt&&flag){
            for(int i=0;i<26;i++){
                flag = false;
                if(exist[i]&&indegree[i]==0){
                    flag = true;
                    cnt--;
                    for(int j=0;j<26;j++){
                        if(G[i][j])
                            indegree[j]--;
                    }
                    exist[i] = false;
                    res.push_back(i+'a');
                    break;
                }
            }
        }
        
        return cnt?"":res;
    }
};

class AlienTest: public Test {
public:
    void test(){
        cout<<"28. Alien Dict"<<endl;
        vector<string> testcase = {"wrt","wrf","er","ett","rftt"};
        Solution S;
        cout<<S.alienOrder(testcase)<<endl;
        printsep();
    }
};

