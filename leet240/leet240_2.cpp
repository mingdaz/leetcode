class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
        return false;
    }
    while (matrix.size() != 0 && matrix[0].size()) {
        if (target < matrix[matrix.size() - 1][0]) {
            matrix.pop_back();
        } else if (target > matrix[matrix.size() - 1][0]) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i].erase(matrix[i].begin());
            }
        } else {
            return true;
        }
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        if (matrix.size() == 1 && matrix[0].size() == 1 && matrix[0][0] != target) {
            return false;
        }
        if (target < matrix[0][matrix[0].size() - 1]) {
            int erase_num = matrix[0].size() - 1;
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i].erase(matrix[i].begin() + erase_num);
            }
        } else if (target > matrix[0][matrix[0].size() - 1]) {
            matrix.erase(matrix.begin());
        } else {
            return true;
        }
        if (matrix.size() == 1 && matrix[0].size() == 1 && matrix[0][0] != target) {
            return false;
        }
    }
    return false;
    }
};
