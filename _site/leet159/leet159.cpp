class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.empty())
            return 0;
        int res = 0, start = 0;
        int idx1 = s.find_first_not_of(s[0]), idx2 = idx1 - 1; // idx of last apperance of a ch
        if(idx1 == string::npos)
            return s.length();
        for(int i = idx2 + 1; i < s.length(); i++) {
            if(s[i] == s[idx1]) {
                idx1 = i;
            } else if(s[i] == s[idx2]) {
                idx2 = i;
            } else {
                res = max(res, i - start);
                if(idx1 < idx2) {
                    start = idx1 + 1;
                    idx1 = i;
                } else {
                    start = idx2 + 1;
                    idx2 = i;
                }
            }
        }
        res = max(res, (int) s.length() - start);
        return res;
    }
};
