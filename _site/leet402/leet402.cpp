class Solution {
public:
    string removeKdigits(string num, int k) {
        int len = num.length()-k;
        string stk(num.length(),'0');
        int top = 0;
        for(char c:num){
            while(top>0&&stk[top-1]>c&&k>0){
                top--;
                k--;
            }
            stk[top++] = c;
        }
        int idx = 0;
        while(idx<len&&stk[idx]=='0') idx++;
        return len==idx?"0":stk.substr(idx,len-idx);
    }
};
