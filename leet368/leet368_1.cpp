class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()<1) return nums; 
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> DP(n,1);
        vector<int> pre(n,-1);

        int max_idx = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(DP[j]+1>DP[i]){
                        DP[i] = DP[j] + 1;
                        pre[i] = j; 
                    }  
                }  
            }
            if(DP[i]>DP[max_idx])
                max_idx = i;
        }
        
        vector<int> res;
        while(DP[max_idx]>1){
            res.push_back(nums[max_idx]);
            max_idx = pre[max_idx];
        }
        res.push_back(nums[max_idx]);
        return res;
    }
};
