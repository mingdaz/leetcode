class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        int i,j,a,b;
        int dp[l1+1][l2+1];
        dp[0][0] = 0;
        for(j=1;j<=l2;j++)dp[0][j] = j;
        for(i=1;i<=l1;i++)dp[i][0] = i;
        
        for(i=1;i<=l1;i++){
            for(j=1;j<=l2;j++){
                a = dp[i-1][j-1]+(word1[i-1]==word2[j-1]?0:1);
                b = min(dp[i][j-1],dp[i-1][j])+1;
                dp[i][j] = min(a,b); 
            }
        }
        return dp[l1][l2];
    }
};