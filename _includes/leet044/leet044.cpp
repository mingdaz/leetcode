class Solution {
public:
    bool isMatch(string s, string p)
    {
        int i=0, j=0;
        int ii = -1, jj = -1;
        while(i<s.length()) {
            if(j < p.length() && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            } else if (j < p.length() && p[j] == '*') {
                jj = j++;
                ii = i;
            } else if (jj != -1) {
                j = jj;
                i = ++ii;
            } else {
                return false;
            }
        }
        while(j < p.length()) {
            if(p[j] != '*') {
                return false;
            }
            j++;
        }
        return true;
    }
};