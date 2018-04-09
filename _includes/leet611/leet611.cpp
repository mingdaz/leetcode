class Solution {
public:
int sum2Greater(const vector<int> &nums, int targetIdx) {
	int ret = 0;
	for(int i=0, j=targetIdx-1; i<j;) {
		if(nums[i] + nums[j] > nums[targetIdx]) {
			ret += j-i;
			j--;
		}
		else {
			i++;
		}
	}
	return ret;
}

int triangleNumber(vector<int>& nums) {
	int total = 0;
    sort(nums.begin(), nums.end());
	for(int i=nums.size()-1; i>=2; i--) {
		int validNum = sum2Greater(nums, i);
		total += validNum;
	}
	return total;
}
};