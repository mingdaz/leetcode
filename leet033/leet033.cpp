class Solution {
public:
    int search(vector<int>& nums, int target) {
    	int l=0,h=nums.size();
	int mid;
	while(l<=h){
		mid = l+(h-l)/2;
		if(tagert>nums[mid]) l = mid+1;
		else if(target<nums[mid]) h = mid-1;
		else return mid;
	}    
	return -1;
    }
};
