class Solution {
public:
    unordered_map<string,bool> dict;
    bool canWin(string s) {
        // if(dict.find(s)!=dict.end()) return dict[s];
        
        for(int i=1;i<s.length();i++){
            if(s[i]=='+'&&s[i]==s[i-1]){
                s[i] = '-';
                s[i-1] = '-';
                if(dict.find(s)==dict.end()) {
                    dict[s] = canWin(s);
                }
                if(!dict[s]) return true;
                s[i] = '+';
                s[i-1] = '+';
            }
        }
        return false;
    }
};
