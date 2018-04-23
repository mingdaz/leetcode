class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int res=0;
        int sign=1;
        int n=s.size();
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c>='0'&&c<='9'){
                int num=0;
                while(i<n&&s[i]>='0'){
                    num=num*10+s[i++]-'0';
                }
                res+=sign*num;
                i--;
            }else if(c=='+'){
                sign=1;
            }else if(c=='-'){
                sign=-1;
            }else if(c=='('){
                stk.push(res);
                stk.push(sign);
                res=0;
                sign=1;   
            }else if(c==')'){
                res*=stk.top();stk.pop();
                res+=stk.top();stk.pop();
            }
        }
        return res;
    }
};