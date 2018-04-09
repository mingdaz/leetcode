class Solution {
public:
    int longestPalindrome(string s) {
        int ret = 0;
        int dic[129] = {};
        // memset(dic, 0, 128* sizeof(int));
        for(char c:s){
            dic[c]++;
        }
        int odd = 0;
        for(int i = 0; i < 128; i++){
            if(dic[i]&1==1){
                dic[i]--;
                odd = 1; 
            }
            ret += dic[i] ;
        }
        return ret + odd;
    }
};
