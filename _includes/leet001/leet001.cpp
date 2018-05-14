class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> dict;
        vector<int> ret(2,0);
        for(int i=0;i<nums.size();i++){
            if(dict.find(target-nums[i])!=dict.end()){
                ret[0] = dict[target-nums[i]];
                ret[1] = i;
                return ret;
            }
            dict[nums[i]] = i;
        }
        return ret;
    }
};