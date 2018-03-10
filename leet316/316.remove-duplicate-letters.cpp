class Solution {
public:
    string removeDuplicateLetters(string s) {
        int counts[26] = {};
        bool inresult[26] = {};
        for(char c: s) counts[c-'a']++;
        string result = "";
        for(char c: s) {
            counts[c-'a']--;
            if(inresult[c-'a']) continue;
            while(!result.empty() && counts[result.back()-'a']>0 && result.back()>c){
                inresult[result.back()-'a'] = false;
                result.pop_back();
            }
            inresult[c-'a'] =true;
            result.push_back(c);
        }
        return result;
    }
};