class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int, int> map;
        map[0] = 1;
        int sum = 0;
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            int sub = sum - k;
            if(map.find(sub) != map.end()) {res += map[sub];map[sum]++;}
            else map[sum]++;
        }
        return res;
    }
};
