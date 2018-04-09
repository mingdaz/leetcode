class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size(), flag = 1, index = len - 1;
        for (int i = len - 1; i>0; i--){
            if (nums[i] <= nums[i - 1]) index--;
            else{
                for (int j = len - 1; j >= index; j--){
                    if (nums[j]>nums[i - 1]){
                        swap(nums[i - 1], nums[j]);
                        break;
                    }
                }
                sort(nums.begin() + i , nums.end());
                flag = 0;
                break;
            }
        }
        if (len&&flag) sort(nums.begin(), nums.end());
    }
};
