class Solution {
public:
       bool repeatedSubstringPattern(string str) {
        int n = str.size();
        vector<int> dp(n+1,0);
        for(int i=1;i<n;i++){
            int j = dp[i];
            while(j&&str[i]!=str[j]) j = dp[j];
            dp[i+1] = str[i]==str[j]?j+1:0;
        }
        return dp[n]&&dp[n]%(n-dp[n])==0;
    }
};
