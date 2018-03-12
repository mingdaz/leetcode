class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size()<2) return true;
        int cap = isupper(word[0]);
        if(!cap&&isupper(word[1])) return false;
        if(cap&&!isupper(word[1])) cap = false;
        for(int i=1;i<word.size();i++){
            if(cap!=isupper(word[i])) return false;
        }
        return true;
    }
};
