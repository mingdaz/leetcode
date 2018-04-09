class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int a = nums[0]>nums[1]?0:1;
        int b = nums[0]>nums[1]?1:0;
        for(int i=2;i<nums.size();i++){
            if(nums[i]>nums[a]){
                b = a;
                a = i;
            }
            else if(nums[i]>nums[b]){
                b = i;
            }
        }
        return nums[a]>=2*nums[b]?a:-1;
    }
};
