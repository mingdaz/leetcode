class Solution {
public:
    int maxA(int N) {
        if (N < 6) return N;
        vector<int> dp(N+1, 0);
        for (int i = 1; i <= 6; i++)
            dp[i] = i;
        for (int i = 7; i <= N; i++) {
            for (int j = 3; j <= 6; j++) 
                dp[i] = max(dp[i], dp[i-j]*(j-1));
        }
        return dp[N];
    }
};
