class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        int left = 0;
        for(int i=0;i<nums.size();i++){
            sum -= nums[i];
            if(sum==left) 
                return i;
            left += nums[i];
        }
        return -1;
    }
};