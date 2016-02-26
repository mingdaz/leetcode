class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        int l = 0,r = nums.size()-1;
        int mid;
        int match = -1;
        while(l<=r){
            mid = l+(r-l)/2;
            if(nums[mid]>target) r = mid-1;
            else if(nums[mid]<target) l = mid+1;
            else {
                match = mid;
                break;
            }
        }
        if(match<0) return res;
        int i;
        for(i=match;i>0;i--){
            if(nums[i]!=nums[i-1]) break;
        }
        res[0] = i;
        for(i=match;i<nums.size()-1;i++){
            if(nums[i]!=nums[i+1]) break;
        }
        res[1] = i;
        return res;

    }
};
