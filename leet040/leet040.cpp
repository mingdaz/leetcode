class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> vec;
        int sum = 0;
        sort(candidates.begin(), candidates.end()); 
        combinationSum2(res, vec, candidates, target, sum, 0);
        return res;
    }

private:
    void combinationSum2(vector<vector<int>>&res, vector<int> &vec,
        vector<int> &candidates, int target, int &sum, int start)
    {
        int tmp = 0; //last state
        for (int i = start; i < candidates.size(); i++){
            if (tmp == candidates[i]) //skip the same value
                continue;
            sum += candidates[i];
            if (sum == target){ //find one
                vec.push_back(candidates[i]);
                res.push_back(vec); 

                sum -= vec.back(); //backtracking
                tmp = vec.back();
                vec.pop_back();
                return;
            }
            else if (sum < target){
                vec.push_back(candidates[i]);
                combinationSum2(res, vec, candidates, target, sum, i+1);
                sum -= vec.back(); //backtracking
                tmp = vec.back();
                vec.pop_back();
            }
            else{
                sum -= candidates[i];
                return;
            }
        }
    }
};
