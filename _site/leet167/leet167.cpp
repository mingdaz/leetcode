class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res(2);
    	int left = 0;
		int right = numbers.size()-1;
		int sum = numbers[left]+numbers[right];
		while(sum!=target){
			if(sum>target){
				while(right>left&&numbers[right]==numbers[--right]);
			}
			else {
				while(right>left&&numbers[left]==numbers[++left]);
			}
			sum = numbers[left]+numbers[right];
		}	
		res[0] = left+1;
		res[1] = right+1;
		return res;
    }
};

