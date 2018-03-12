class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.empty()) return res;
        string cur = to_string(nums[0]);
        int l = 0;
        int r = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]+1){
                r++; 
            }
            else{
                if(r>l)
                    cur = cur + "->" + to_string(nums[r]);
                res.push_back(cur);
                l = i;
                r = i;
                cur = to_string(nums[l]);
            }
        }
        if(r>l)
            cur = cur + "->" + to_string(nums[r]);
        res.push_back(cur);
        return res;
    }
};
