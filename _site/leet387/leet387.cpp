class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> cnt = vector<int>(128,0);
        for(char a:s){
            cnt[a]++;
        }
        for(int i=0;i<s.length();i++){
            if(cnt[s[i]]==1) return i;
        }
        return -1;
    }
};
