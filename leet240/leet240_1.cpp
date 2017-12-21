class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int row = 0, col = matrix[0].size() - 1;
        while(row < matrix.size() && col < matrix[0].size()) {
            if (target == matrix[row][col]) {
                return true;
            } 
            if (target < matrix[row][col]) {
                col--;
            }else{
                row++;
            }
         }
        return false;
  
    }
};
