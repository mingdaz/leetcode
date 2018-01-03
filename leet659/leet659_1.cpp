class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size(), k = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i]-nums[i-1] > 1) {
                if (!check(nums, k, i)) 
                    return false;
                k = i;
            }
        }
        return check(nums, k, n);
    }
private:
    bool check(vector<int>& nums, int s, int e) {
        int ones = 0, twos = 0, tot = 0;
        for (int i = s+1, cnt = 1; i <= e; i++) {
            if (i < e && nums[i] == nums[i-1])
                cnt++;
            else {
                if (cnt < ones + twos) return false;
                twos = ones;
                ones = max(0, cnt-tot);
                tot = cnt;
                cnt = 1;
            }
        }
        return ones == 0 && twos == 0;
    }
};
