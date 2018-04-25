//
//  11_csv_parse.cpp
//  airbnb
//
//  Created by Zhang, Mingda on 4/25/18.
//  Copyright © 2018 Zhang, Mingda. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "Test.hpp"

class csvparser{
public:
    string parse(string lines){
        string ret;
        int i=0;
        while(i<lines.size()){
            if(lines[i]=='"'){
                string field = "";
                if(++i<lines.size()&&lines[i]=='"'){
                    
                }
            }
            else{
                ret.push_back('\n');
            }
            i++;
        }
        return ret;
    }
};
