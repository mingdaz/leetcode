class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        if(matrix.size()==0||matrix[0].size()==0) return;
        sum.resize(matrix.size(),vector<int>(matrix[0].size(),0));
        int i,j;
        for(i=0;i<matrix.size();i++){
            for(j=1,sum[i][0]=matrix[i][0];j<matrix[0].size();j++){
                sum[i][j] = sum[i][j-1] + matrix[i][j];             
            }
        }
    }
    
    void update(int row, int col, int val) {
        int diff = val - sum[row][col] + (col>0?sum[row][col-1]:0);
        for(int i=col;i<sum[0].size();i++){
            sum[row][i] += diff;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ret = 0;
        for(int i=row1;i<=row2;i++){
            ret += (sum[i][col2] - (col1>0?sum[i][col1 -1]:0));
        }
        return ret;
    }
    vector<vector<int>> sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */