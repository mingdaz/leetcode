class Solution {
public:
    int calculate(string s) {
        stack<int> S;
        int res = 0;
        int cur = 0;
        int op = '+';
        for(size_t i=0;i<s.size();i++){
            if(s[i]==' ') continue;
            if(isdigit(s[i])){
                int num = 0;
                while(i<s.size()&&isdigit(s[i])){
                    num = num*10 + s[i] - '0';
                    i++;
                }
                i--;
                switch(op){
                    case '+': cur += num;break;
                    case '-': cur -= num;break;
                    case '*': cur *= num;break;
                    case '/': cur /= num;break;
                }
            }
            else if(s[i]=='('){
                S.push(res);
                S.push(cur);
                S.push(op);
                res = 0;
                cur = 0;
                op = '+';
            }
            else if(s[i]==')'){
                int num = res + cur;
                op = S.top();S.pop();
                cur = S.top();S.pop();
                res = S.top();S.pop();
                switch(op){
                    case '+': cur += num;break;
                    case '-': cur -= num;break;
                    case '*': cur *= num;break;
                    case '/': cur /= num;break;
                }
            }
            else{
                if(s[i]=='+'||s[i]=='-'){
                    res += cur;
                    cur = 0;
                }
                op = s[i];
            }
        }
        return res + cur;
    }
};