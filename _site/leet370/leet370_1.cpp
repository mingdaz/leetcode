class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> result(length, 0);
        for(auto &op: updates)
        {
            result[op[0]] += op[2];
            if(op[1] + 1 < result.size())
            result[op[1] + 1] -= op[2];
        }
        
        int sum = 0;
        for(int i = 0; i < result.size(); ++i)
        {
        //    cout << result[i] << endl; 
            sum += result[i];
            result[i] = sum;
        }
        
        return result;
    }
};
