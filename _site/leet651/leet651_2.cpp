//O(1) space
class Solution {
public:
    int maxA(int N) {
        if (N < 6) return N;
        vector<int> dp(6, 0);
        for (int i = 0; i < 6; i++)
            dp[i] = i;
        for (int i = 6; i <= N; i++) {
            int tmp = 0;
            for (int j = 0; j <= 3; j++) 
                tmp = max(tmp, dp[j]*(5-j));
            for (int j = 0; j < 5; j++)
                dp[j] = dp[j+1];
            dp.back() = tmp;
        }
        return dp.back();
    }
};
