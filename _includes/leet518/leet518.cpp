class Solution {
public:
  int change(int amount, vector<int>& coins) {
    if (amount==0)
      return 1;
    if (coins.size()==0)
      return 0;
    vector<int>dp(amount+1,0);
    dp[0]=1;
    for(int i=0; i<coins.size();i++)
    {
      for(int k=coins[i];k<=amount;k++)
      {
        dp[k]+=dp[k-coins[i]];
      }
    }
    return dp[amount];
  }
};