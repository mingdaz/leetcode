class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        dp[1] = 1; 
        for(int i = 2;i<=n;i++){
            int cnt = i;
            for(int j=1;j*j<=i;j++){
                cnt = min(cnt,dp[i-j*j] + 1);
            }
            dp[i] = cnt;
        }
        return dp[n];
    }
};