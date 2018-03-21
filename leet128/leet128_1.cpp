class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = 0;
        unordered_set<int> dict(nums.begin(), nums.end());

        while (dict.size() > 0) {
            int n = *dict.begin();
            dict.erase(n);
            int l = n-1 , r = n+1;
            while (dict.find(l) != dict.end()) {dict.erase(l--);}
            while (dict.find(r) != dict.end()) {dict.erase(r++);}
            len = max(len, r - l-1);
        }

        return len;
    }
};