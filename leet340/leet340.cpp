class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int dist) {
        // int dist = 2;
        vector<int> cnt(256,0);
        int i = 0;
        int j = 0;
        int ret = 0;
        while(j<s.size()){
            if(cnt[s[j]]==0){
                if(dist==0){
                    ret = max(ret,j-i);
                    while(i<j&&cnt[s[i]]>1){
                        cnt[s[i]]--;
                        i++;
                    }
                    cnt[s[i]]--;
                    i++;
                    dist++;
                }
                dist--;
            }
            cnt[s[j]]++;
            j++;
        }
        ret = max(ret,j-i);
        return ret;
    }
};