class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> DP(n+1,vector<int>(n+1,0));
        for(int d=1;d<n;d++){
            for(int i=1;i<=n-d;i++){
                 // DP[i][i+d] 
                int val = INT_MAX;
                for(int k=i;k<=i+d;k++){
                    val = min(val,k+max(DP[i][k-1],k==n?0:DP[k+1][i+d]));
                }
                DP[i][i+d] = val;
            }
        }
        return DP[1][n];
    }
};
