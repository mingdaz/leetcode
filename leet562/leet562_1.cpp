class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int nr = M.size();
        if (M[0].empty()) return 0;
        int nc = M[0].size();
        
        int maxc = 0;
        vector<int> horizontal(nc, 0), vertical(nr, 0), diag1(nc+nr-1, 0), diag2(nc+nr-1, 0);
        for (int i=0; i<nr; ++i) {
            for (int j=0; j<nc; ++j) {
                if (M[i][j] == 1) {
                    maxc = std::max(maxc, ++horizontal[j]);
                    maxc = std::max(maxc, ++vertical[i]);
                    maxc = std::max(maxc, ++diag1[i+j]);
                    maxc = std::max(maxc, ++diag2[i+nc-1-j]);
                }
                else {
                    horizontal[j] = 0;
                    vertical[i] = 0;
                    diag1[i+j] = 0;
                    diag2[i+nc-1-j] = 0;
                }
            }
        }
        return maxc;
    }
};
