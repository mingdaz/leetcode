class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
		vector<string> res;
		
		for(int i=0;i<nums.size()&&lower<=upper;i++){
			if(nums[i]<lower) continue;
			if(nums[i]==lower) lower++;
			else if(nums[i]>upper) break;
			else{
				string range = to_string(lower);
				if(nums[i]>lower+1){
					range.append("->");
					range.append(to_string(nums[i]-1));
				}
				res.push_back(range);
				lower = nums[i]+1;
			}
		}
		if(lower<=upper){
			string range = to_string(lower);
			if(upper>lower){
				range.append("->");
				range.append(to_string(upper));
			}
			res.push_back(range);
		}		
		return res;
    }
};
