class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> res;
        string tmp(n,'0');
        int l=0,r=n-1;
        dfs(tmp,res,l,r);
        return res;
    }
    
    void dfs(string& tmp,vector<string> &res,int l,int r){
        if(l>r){ 
            res.push_back(tmp);
        }
        else if(l==r){
            tmp[l]='0';
            res.push_back(tmp);
            tmp[l]='1';
            res.push_back(tmp);
            tmp[l]='8';
            res.push_back(tmp);
        }
        else{
            if(l>0){
                tmp[l]='0';
                tmp[r]='0';
                dfs(tmp,res,l+1,r-1);
            }
            tmp[l]='1';
            tmp[r]='1';
            dfs(tmp,res,l+1,r-1);
            tmp[l]='6';
            tmp[r]='9';
            dfs(tmp,res,l+1,r-1);
            tmp[l]='8';
            tmp[r]='8';
            dfs(tmp,res,l+1,r-1);
            tmp[l]='9';
            tmp[r]='6';
            dfs(tmp,res,l+1,r-1);
        }
        return;
        
    }
};
