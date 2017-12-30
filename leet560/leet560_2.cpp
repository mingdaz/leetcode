class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        for (int i = 1; i < nums.size(); ++i){
            nums[i] += nums[i-1];
        }
        
        unordered_map<int, int> hash_rec;
        hash_rec[0] = 1;
        
        int result = 0;
        
        for (int i = 0; i < nums.size(); ++i){
            if (hash_rec.count(nums[i] - k)){
                result += hash_rec[nums[i] - k];
            }
            if (hash_rec.count(nums[i]))
                ++hash_rec[nums[i]];
            else
                hash_rec[nums[i]] = 1;
        }
        
        return result;
    }
};
