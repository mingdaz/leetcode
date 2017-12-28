class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<char> mark(9,0);
        int cnt = 0;
        dfs(mark,cnt,m,n,0,-1);
        return cnt;
    }
private:
    // 0,1,2,
    // 3,4,5,
    // 6,7,8
    
    vector<vector<char>> check = {
        {-1,-1,1,
         -1,-1,-1,
         3,-1,4},
        {-1,-1,-1,
         -1,-1,-1,
         -1,4,-1},
        {1,-1,-1,
         -1,-1,-1,
         4,-1,5},
        {-1,-1,-1,
         -1,-1,4,
         -1,-1,-1},
        {-1,-1,-1,
         -1,-1,-1,
         -1,-1,-1},
        {-1,-1,-1,
         4,-1,-1,
         -1,-1,-1},
        {3,-1,4,
         -1,-1,-1,
         -1,-1,7},
        {-1,4,-1,
         -1,-1,-1,
         -1,-1,-1},
        {4,-1,5,
         -1,-1,-1,
         7,-1,-1}
        
    };
    void dfs(vector<char>& mark,int & cnt,int& m, int& n,int k,int pre){
        if(k>n) return;
        if(k>=m) cnt++;
        for(int i=0;i<9;i++){
            if(!mark[i]){
                if(pre<0||check[pre][i]<0||mark[check[pre][i]]){
                    mark[i] = 1;
                    dfs(mark,cnt,m,n,k+1,i);
                    mark[i] = 0;
                }
            }
        }
    }
};
