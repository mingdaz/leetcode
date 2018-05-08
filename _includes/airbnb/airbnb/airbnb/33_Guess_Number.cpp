//
//  33_Guess_Number.cpp
//  airbnb
//
//  Created by Zhang, Mingda on 5/5/18.
//  Copyright © 2018 Zhang, Mingda. All rights reserved.
//

#include <vector>
#include <iostream>
#include <unordered_set>
#include "Test.hpp"

using namespace std;
class Server{
public:
    Server(string number){
        this->number = number;
    }
    pair<int,int> guess(string guess){
        vector<int> d_secret(10,0);
        vector<int> d_guess(10,0);
        
        int A=0;
        int B=0;
        for(int i=0;i<4;i++){
            d_secret[number[i]-'0']++;
            d_guess[guess[i]-'0']++;
            if(guess[i]==number[i]) {
                A++;
                d_secret[number[i]-'0']--;
                d_guess[guess[i]-'0']--;
            }
        }
        for(int i=0;i<10;i++){
            if(d_secret[i]) {
                B += min(d_secret[i],d_guess[i]);
            }
        }
        return pair<int,int>(A,B);
    }
    
    void set_number(string number){
        this->number = number;
    }
private:
    string number;
};


class Solver{
public:
    string solve(Server& s){
        unordered_set<string> pool;
        string path = "";
        create(pool,4,1,6,path);
        while(true){
            auto random_it = next(begin(pool), rand()%pool.size());
            string guess = *random_it;
            auto p = s.guess(guess);
            cout<<guess<<",["<<p.first<<"A"<<p.second<<"B]"<<endl;
            if(p.first==4) return guess;
            pool.erase(guess);
            clear(pool,p,guess);
        }
        return "";
    }
private:
    void create(unordered_set<string>& pool, int digits, int start, int end, string& path){
        if(path.size()==digits){
            pool.insert(path);
            return;
        }
        for(char i=start+'0';i<=end+'0';i++){
            path.push_back(i);
            create(pool,digits,start,end,path);
            path.pop_back();
        }
    }
    void clear(unordered_set<string>& pool, pair<int,int> res, string& guess){
        for(auto it = pool.begin();it!=pool.end();){
            vector<int> d_secret(10,0);
            vector<int> d_guess(10,0);
            
            int A=0;
            int B=0;
            for(int i=0;i<4;i++){
                d_secret[(*it)[i]-'0']++;
                d_guess[guess[i]-'0']++;
                if(guess[i]==(*it)[i]) {
                    A++;
                    d_secret[(*it)[i]-'0']--;
                    d_guess[guess[i]-'0']--;
                }
            }
            for(int i=0;i<10;i++){
                if(d_secret[i]) {
                    B += min(d_secret[i],d_guess[i]);
                }
            }
            if(A==res.first&&B==res.second)
                ++it;
            else
                it = pool.erase(it);
        }
    }
};

class GuessNumberTest: public Test {
public:
    void test(){
        Server S("6345");
        Solver s;
        s.solve(S);
        printsep();
    }
};
