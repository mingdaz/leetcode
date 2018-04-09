class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(); //3
        int n = matrix[0].size(); //4
        for(int dif=m-1;dif>-n;dif--){   //sum=2,3,4,5,
            int idx = max(0,-dif);
            int tmp = matrix[idx+dif][idx];
            for(int j=idx+1;j<min(m-dif,n);j++){
               if(matrix[j+dif][j]!=tmp) return false;
           }
        }
        return true;       
    }
};
