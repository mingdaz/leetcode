class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if(!n) return -1;
        priority_queue<int> Q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                Q.push(matrix[i][j]);
                while(Q.size()>k) Q.pop();
            }
        }
        return Q.top();
             
    }
};
