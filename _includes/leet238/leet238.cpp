class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pro(n, 1);
        for (int i = 1; i < n; ++i) {
            pro[i] = pro[i-1] * nums[i-1];
        }
        
        //multiply from right to left.
        int right = 1;
        for (int i = n - 2; i >= 0; --i) {
            right *= nums[i+1];
            pro[i] *= right;
        }
        return pro;
    }
};