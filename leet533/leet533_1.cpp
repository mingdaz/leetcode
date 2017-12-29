
class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        unordered_map<string, int> um;
        int m = picture.size(), n = m == 0 ? 0 : picture[0].size();
        if(m == 0 || n == 0) return 0;
        vector<int> colcnt(n, 0);
        for(int i = 0;i < m;i++) {
            string s = "";
            int rowcnt = 0;
            for(int j = 0;j < n;j++) {
                s += picture[i][j];
                if(picture[i][j] == 'B') { 
                    colcnt[j]++;
                    rowcnt++;
                }
            }
            if(rowcnt == N)
                um[s]++;
        }
        int res = 0;
        for(auto &e: um) {
            if(e.second == N)
                for(int i = 0;i < n;i++)
                    if(e.first[i] == 'B' && colcnt[i] == N)
                        res += N;
        }
        return res;
    }
};
