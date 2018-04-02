class Solution {
private:
    int count(int diff, vector<int> & nums){
        int j = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i){
            while(j < nums.size() && nums[j] - nums[i] <= diff){
                ++j;
            }
            cnt += j - i - 1;
        }
        return cnt;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if (nums.size() == 0)
            return 0;
        int dMin = INT_MAX;
        
        for (int i = 0; i < nums.size()-1; ++i){
            dMin = min(nums[i+1] - nums[i], dMin);
        }
        int dMax = nums.back() - nums[0];
        
        while (dMin < dMax){
            int md = dMin + (dMax-dMin)/2;
            if (count(md, nums) >= k){
                dMax = md;
            }
            else{
                dMin = md+1;
            }
        }        
        return dMin;
    }
};