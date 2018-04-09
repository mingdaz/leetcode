class Solution {
public:
    bool canWin(string s) {
        for(int i=1;i<s.length();i++){
            if(s[i]=='+'&&s[i]==s[i-1]){
                s[i] = '-';
                s[i-1] = '-';
                if(!canWin(s)) return true;
                s[i] = '+';
                s[i-1] = '+';
            }
        }
        return false;
    }
};
