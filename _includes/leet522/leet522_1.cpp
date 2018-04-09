class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int res = -1;
        /*vector<vector<bool>> subseq(strs.size(), vector<bool>(strs.size(), true));
        for(int i = 0;i < strs.size();i++)
            for(int j = i+1;j < strs.size();j++) {
                subseq[i][j] = isSubseq(strs[i], strs[j]);
                subseq[j][i] = isSubseq(strs[j], strs[i]);
            }*/
                
        for(int i = 0;i < strs.size();i++) {
            bool unCommon = true;
            for(int j = 0;j < strs.size();j++)
                if(i == j )
                    continue;
                else {
                    if(isSubseq(strs, i, j)) {
                        unCommon = false;
                        break;
                    }
                }
            if(unCommon)
                res = max(res, int(strs[i].size()));
        }
        return res;
            
    }
    bool isSubseq(vector<string>& s, int p, int q) {
        string a = s[p], b = s[q];
        if(a.size() > b.size())
            return false;
        int i = 0, j = 0;
        while(i < a.size() && j < b.size()) {
            if(a[i] == b[j])
                i++;
            j++;
        }
        if(i == a.size())
            return true;
        return false;
    }
};
