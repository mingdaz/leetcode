class Solution {
public:
    string reverseStr(string s, int k) {
        size_t i,p,q,r;
        char tmp;
        for(i=0; i < s.length();i += 2*k){
            r = i+k-1;
            for(p=i,q= (r < s.length() ? r : s.length()-1);p<q;p++,q--){   
                tmp = s[p];
                s[p] = s[q];
                s[q] = tmp;
            }
        }
        return s;
    }
};
