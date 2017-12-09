class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        for(int i=0;i<nums.size();i++){
            while(nums[nums[i]-1]!=nums[i])
                swap(nums[i],nums[nums[i]-1]);            
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i] != i+1) ret.push_back(i+1);
        }
        return ret;
    }
};
