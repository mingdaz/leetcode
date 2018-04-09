class Solution {
public:
   /* bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) dp[i] = nums[i];
        for (int k = 1; k < n; ++k) {
            int prev = dp[k-1];
            for (int j = k; j < n; ++j) {
                int i = j-k, cur = dp[j];
                dp[j] = max(nums[i]-dp[j], nums[j]-prev);
                prev = cur;
            }
        }
        return dp[n-1] >= 0;
    }*/
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) 
            dp[i][i] = nums[i];
        for (int k = 1; k < n; k++) {
            for (int i = 0; i+k < n; i++) {
                int j = i+k;
                int t1 = nums[i] - dp[i+1][j];
                int t2 = nums[j] - dp[i][j-1];
                dp[i][j] = max(t1, t2);
            }
        }
        return dp[0][n-1] >= 0;
    }
};