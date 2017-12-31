class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> res;
        DFS(res,"","",n);
        return res;
    }
private:
    void DFS(vector<string>& res, string l, string r, int n){
        if(n==0) res.push_back(l+r);
        else if(n==1){
            res.push_back(l+"0"+r);
            res.push_back(l+"1"+r);
            res.push_back(l+"8"+r);
        }
        else{
            n -=2;
            DFS(res,l+"1","1"+r,n);
            DFS(res,l+"6","9"+r,n);
            DFS(res,l+"8","8"+r,n);
            DFS(res,l+"9","6"+r,n);
            if(!l.empty())
               DFS(res,l+"0","0"+r,n); 
        }
    }
};
