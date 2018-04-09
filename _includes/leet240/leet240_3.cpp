static int kap = [](){
    std::ios::sync_with_stdio(false);
    return 0;
}();

class Solution {
public:
    int getNewC(int r, int c, int target, const std::vector<std::vector<int>>& matrix)
    {
        while (c >= 0)
        {
            if (matrix[r][c] == target) return -1;
            if (matrix[r][c] < target)  return c;
            --c;
        }
        
        if (matrix[r][c + 1] > target) return -2;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        
        int M{matrix.size()}, N{matrix[0].size()};
        int r{0}, c{N - 1};
        
        while (r < M && c >= 0)
        {
            if (matrix[r][c] == target) return true;
            else if (matrix[r][c] < target)  ++r;
            else
            {
                c = getNewC(r, c - 1, target, matrix);
                if (c == -1)    return true;
                ++r;
            }
        }
        
        return false;
    }
};
