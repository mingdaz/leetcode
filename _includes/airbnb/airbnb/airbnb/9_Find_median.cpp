//
//  9_Find_median.cpp
//  airbnb
//
//  Created by Zhang, Mingda on 4/23/18.
//  Copyright © 2018 Zhang, Mingda. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "Test.hpp"
using namespace std;

class FindMedian{
private:
    int Search(vector<int>& nums, int k, long left, long right){
        if(left>=right){
            return left;
        }
        long res = left;
        long mid = left + (right - left)/2;
        int cnt = 0;
        for(long num:nums){
            if(num<=mid){
                cnt++;
                res = max(res,num);
            }
        }
        if(cnt==k)
            return res;
        else if(cnt<k){
            return Search(nums, k, max(res+1,mid), right);
        }
        else
            return Search(nums, k, left, res);
    }
public:
    double findMedian(vector<int>& nums){
        int len = 0;
        for(int num:nums){
            len++;
        }
        if(len%2==1){
            return (double) Search(nums, len/2+1, INT_MIN, INT_MAX);
        }
        else{
            int a = Search(nums, len/2, INT_MIN, INT_MAX);
            int b = Search(nums, len/2+1, INT_MIN, INT_MAX);
            return (double) (Search(nums, len/2, INT_MIN, INT_MAX) + Search(nums, len/2+1, INT_MIN, INT_MAX))/2;
        }
    }
};

class FindMedianTest: public Test{
public:
    void test(){
        vector<int> testcase = {1,2,2,2,2,2};
        cout<<"9. find median"<<endl;
        FindMedian f;
        cout<<f.findMedian(testcase)<<endl;
        printsep();
    }
};
