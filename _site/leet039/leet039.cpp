class Solution {
public:
     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;

        std::sort(candidates.begin(),candidates.end());
        Create_combinationSum(candidates,target,result,combination);

        return result;
    }

    void Create_combinationSum(vector<int>& candidates, int target, vector<vector<int>> &solutions, vector<int> & combination, int minIndex = 0)
    {
        if(target == 0) solutions.push_back(combination);
        while(minIndex < candidates.size())
        {
            if(target < candidates[minIndex]) break;
            else if(target == candidates[minIndex] || target >= 2 * candidates[minIndex])
            {
                combination.push_back(candidates[minIndex]);
                Create_combinationSum(candidates,target - candidates[minIndex], solutions, combination, minIndex);
                combination.pop_back();
            }
            minIndex++;
        }
    }
};
