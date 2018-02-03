class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(auto str:strs){
            int ones = 0;
            int zeros = 0;
            for(auto c:str){
                if(c=='0') zeros++;
                else ones++;
            }
            for(int i=m;i>=zeros;i--){
                for(int j=n;j>=ones;j--){
                    dp[i][j] = max(1+dp[i-zeros][j-ones],dp[i][j]);
                }
            }
        }
        return dp[m][n];
    }    
};
