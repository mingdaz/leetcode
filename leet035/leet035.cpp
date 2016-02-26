class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums[0]>=target) return 0;
        if(nums.back()<target) return nums.size();
        int l=0,r=nums.size()-1;
        int mid;
        while(l<r){
            mid = l+(r-l)/2;
            if(nums[mid]>target) r = mid-1;
            else if(nums[mid]<target) l = mid+1;
            else return mid;
        }
        if(nums[l]>=target) return l;
        else return l+1;
    }
};
