class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
           int i,j,n = nums.size();
        for(i=0;i<n;i++){
            int cur=nums[i];
            // if in place or non-pos or out of bounds, skip.
            if(cur==i+1||cur<=0||cur>n)continue;
            swap(nums[i],nums[cur-1]);
            // if not the same, then reprocess it.
            if(nums[i]!=nums[cur-1])
                i--;
        }

        for(i=0;i<n;i++)
            if(nums[i]!=i+1) 
                return i+1;
        return n+1;
    }
};
