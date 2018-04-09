class Solution {
public:
    int maxSubArray(vector<int>&A) {
        int n = A.size();
        int ans=A[0],i,sum=0;
        for(i=0;i<n;i++){
            sum+=A[i];
            ans=max(sum,ans);
            sum=max(sum,0);
        }
        return ans;
    }
};