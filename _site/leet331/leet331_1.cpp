class Solution {
public:
    bool isValidSerialization(string preorder) {
        int i = 0;
        char flag;
        stack<char> stk;
        
        if(isdigit(preorder[i])){
            while(isdigit(preorder[i]))i++;
            stk.push(0);
        }
        else if(preorder[i]=='#') i++;
        
        while(!stk.empty()&&i<preorder.size()){
            if(preorder[i]==',') i++;
            else if(isdigit(preorder[i])){
                while(isdigit(preorder[i]))i++;
                stk.push(0);
            }
            else if(preorder[i]=='#'){
                if(stk.empty()){
                    return false;
                } 
                flag = 2;
                while(!stk.empty()&&flag==2){
                    // std::cout
                    flag = stk.top();
                    stk.pop();
                    flag++;
                }
                if(flag==1) 
                    stk.push(flag);
                i++;
            }
        }
        return stk.empty()&&i==preorder.size();
    }
};
