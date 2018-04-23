class Solution {
public:
    int calculate(string s) {
        int res = 0;
        int cur = 0;
        char op = '+';
        for(size_t i=0;i<s.size();i++){
            if(s[i]==' ') continue;
            if(isdigit(s[i])){
                int num = 0;
                while(i<s.size()&&isdigit(s[i])){
                    num = num *10 + s[i] - '0';
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