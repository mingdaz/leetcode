class Solution {
public:
    unordered_map<string,bool> dict;
    bool canWin(string s) {
        
        for(int i=1;i<s.length();i++){
            if(s[i]=='+'&&s[i]==s[i-1]){
                s[i] = '-';
                s[i-1] = '-';
                if(dict.find(s)==dict.end()) {
                    dict[s] = canWin(s);
                }
                if(!dict[s]){
                    s[i] = '+';
                    s[i-1] = '+';
                    dict[s] = true;
                    return true;  
                } 
                s[i] = '+';
                s[i-1] = '+';
            }
        }
        dict[s] = false;
        return false;
    }
};
