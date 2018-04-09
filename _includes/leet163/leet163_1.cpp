class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, long int lower, int upper) {
        vector<string> res;
        for(int i=0;i<nums.size()&&lower<=upper;i++){
            if(nums[i]>lower){
                if(nums[i]-1==lower) res.push_back(to_string(lower));
                else {
                    res.push_back(to_string(lower)+"->"+to_string(nums[i]-1));
                }
            }
            lower = long(nums[i])+1;
        }
        if(lower<=upper){
            if(upper==lower) res.push_back(to_string(lower));
            else {
                    res.push_back(to_string(lower)+"->"+to_string(upper));
            }
        }
        return res;
    }
};
