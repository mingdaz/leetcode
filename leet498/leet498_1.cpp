class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int M = matrix.size();
        vector<int> res;
        if(!M) return res;
        int N = matrix[0].size();
        res.resize(M*N,0);
        int idx = 0;
        for(int s=0;s<M+N-1;s++){
            for(int i=max(0,s-M+1);i<=min(s,N-1);i++){
                res[idx++] = matrix[s-i][i];
            }
            s++;
            if(s<M+N-1){
                for(int i=min(s,N-1);i>=max(0,s-M+1);i--){
                    res[idx++] = matrix[s-i][i];
                }
            }
        }
        return res;
    }
};
