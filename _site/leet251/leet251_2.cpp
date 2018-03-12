class Vector2D {
private:
    int numRow;
    int row;
    int col;
    vector<vector<int>> grid;
    
public:
    Vector2D(vector<vector<int>>& vec2d) {
        numRow = vec2d.size();
        grid = vec2d;
        row = 0;
        while (row < numRow && grid[row].size() == 0) {
            row++;
        }
        col = 0;
    }

    int next() {
        int result = grid[row][col];
        if (col + 1 < grid[row].size()) {
            col++;
            return result;
        }
        row++;
        while (row < numRow && grid[row].size() == 0) {
            row++;
        }
        col = 0;
        return result;
    }

    bool hasNext() {
        if (row >= numRow) {
            return false;
        }
        if (col < grid[row].size()) {
            return true;
        }
        int i = row + 1;
        while (i < numRow) {
            if (grid[i].size() > 0) {
                return true;
            }
            i++;
        }
        return false;
    }
};
