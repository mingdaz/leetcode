class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> v1(256, -1), v2(256, -1);
        for(int i=0; i<s.size(); ++i)
        {
            if(v1[s[i]] != v2[t[i]])
                return false;
            
            v1[s[i]] = v2[t[i]] = i;
        }
        
        return true;
    }
};