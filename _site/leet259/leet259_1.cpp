class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int ret=0;
        for(int i=0; i<n; ++i)
        {
            for(int j=i+1, k=n-1; j<k;)
            {
                if(nums[i]+nums[j]+nums[k]<target)
                {
                    ret=ret+(k-j); 
                    j++;
                }
                else k--;
            }
        }
        return ret;
    }
};
