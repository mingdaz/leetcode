class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if(seqs.empty()) return false;
        vector<int> pos(org.size() + 1);
        for(int i = 0; i < org.size(); ++i) 
            pos[org[i]] = i;
        vector<char>flag(org.size() + 1, 0);
        int toMatch = org.size() - 1;
        bool notempty = false;
        for(auto s : seqs){
            for(int i = 0; i < s.size(); ++i){
                notempty = true;
                //org contains from 1 to n, so if there is a number larger than n, then it doesn't exist in the org
                if(s[i] <= 0 || s[i] > org.size()) return false;
                if(i == 0) continue;
                int x = s[i-1];
                int y = s[i];
                if(pos[x] >= pos[y]) return false;
                if(flag[x] == 0 && pos[x]+1 == pos[y]){
                    flag[x] = 1;
                    --toMatch;
                }
            }
        }
        return toMatch == 0 && notempty;
    }
};
