/*
Input: Set[], set_size
1. Get the size of power set
    powet_set_size = pow(2, set_size)
2  Loop for counter from 0 to pow_set_size
     (a) Loop for i = 0 to set_size
          (i) If ith bit in counter is set
               Print ith element from set for this subset
     (b) Print seperator for subsets i.e., newline
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        std::sort(nums.begin(),nums.end());
        int set_size = nums.size();
        int pow_set_size = pow(2,nums.size());
        for(int i=0;i<pow_set_size;i++){
            vector<int> tmp;
            for(int j=0;j<set_size;j++){
                if(i&(1<<j))
                    tmp.push_back(nums[j]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};