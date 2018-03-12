class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if(m==0) return n;
        if(n==0) return m;
        int DP[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0||j==0)
                    DP[i][j] = 0;
                else if(word1[i-1]==word2[j-1])
                    DP[i][j] = DP[i-1][j-1] + 1;
                else 
                    DP[i][j] = max(DP[i][j-1],DP[i-1][j]);
            }
        }
        return m+n - DP[m][n]*2;
    }
};
