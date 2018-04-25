//
//  12_text_justification.cpp
//  airbnb
//
//  Created by Zhang, Mingda on 4/25/18.
//  Copyright © 2018 Zhang, Mingda. All rights reserved.
//

#include <string>
#include <iostream>
#include <vector>
#include "Test.hpp"
using namespace std;

class TextJustification {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        for(size_t i=0;i<words.size();i++){
            int length = 0;
            int cnt = 0;
            int j = i;
            while(i<words.size()&&(length+words[i].size())<=(maxWidth-cnt)){
                length += words[i].size();
                i++;
                cnt++;
            }
            if(i==words.size()){
                string tmp = "";
                for(;j<i;j++){
                    tmp += words[j] + " ";
                }
                if(tmp.size()>maxWidth)
                    tmp.pop_back();
                else{
                    tmp += string(maxWidth- tmp.size(),' ');
                }
                res.push_back(tmp);
            }
            else {
                cnt--;
//                length -= words[i].size();
                int space = maxWidth - length;
                int base = space/cnt;
                int offset = j + space%cnt;
                string tmp = "";
                string a(base,' ');
                string b(base+1,' ');
                for(;j<i;j++){
                    if(j<offset)
                        tmp += words[j] + b;
                    else if(j<i-1)
                        tmp += words[j] + a;
                    else
                        tmp += words[j];
                }
                res.push_back(tmp);
            }
            i--;
        }
        return res;
    }
};

class TextJustificationTest: public Test {
public:
    void test(){
        cout<<"12. Text Justification"<<endl;
        TextJustification t;
        vector<string> testcase = {"This", "is", "an", "example", "of", "text", "justification."};
        vector<string> res = t.fullJustify(testcase, 16);
        for(auto str:res){
            cout<<str<<endl;
        }
        printsep();
    }
};
