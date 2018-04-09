class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size();
        int k = days[0].size(); 
        vector<int> DP(n,-1);
        DP[0] = 0;
        for(int i=0;i<k;i++){
            vector<int> tmp(n,-1);
            for(int j=0;j<n;j++){
                if(DP[j]!=-1){
                    for(int p=0;p<n;p++){
                        if(p==j||flights[j][p]==1)
                            tmp[p] = max(tmp[p],DP[j]+days[p][i]);
                    }
                }
            }
            DP = tmp;
        }
        return *max_element(DP.begin(),DP.end());
    }
};
