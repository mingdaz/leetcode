class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pair<int,int>> score_ind(nums.size());
        vector<string> res = vector<string>(nums.size(),"");
        for(int i=0;i<nums.size();i++){
            score_ind[i] = make_pair(nums[i],i);
        }
        sort(score_ind.rbegin(),score_ind.rend());
        for(int i=0;i<nums.size();i++){
            if(i==0) res[score_ind[i].second] = "Gold Medal";
            else if(i==1) res[score_ind[i].second] = "Silver Medal";
            else if(i==2) res[score_ind[i].second] = "Bronze Medal";
            else res[score_ind[i].second] = to_string(i+1);
        }
        return res;
    }
};
