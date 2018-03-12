class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int i,j,beg = -1,end = -2,n = nums.size();
        int max_val = nums[0],min_val = nums[n-1];
        for(i=0,j=n-1;i<n;i++,j--){
            max_val = max(max_val,nums[i]);
            min_val = min(min_val,nums[j]);
            if(nums[i]<max_val) end = i;
            if(nums[j]>min_val) beg = j;
        }
        return end-beg+1;
    }
};
