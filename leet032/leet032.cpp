class Solution {
public:
    int longestValidParentheses(string s) {
        int max_diff = 0;
        stack<int> stk;
        stk.push(-1);
        int l = s.length();
        for(int i=0;i<l;++i){
            if(s[i]=='(')
                stk.push(i);
            else{
                stk.pop();
                if(stk.empty()) stk.push(i);
                else max_diff = max(i-stk.top(),max_diff);
            }
                
        }
        return max_diff;
    }
};
