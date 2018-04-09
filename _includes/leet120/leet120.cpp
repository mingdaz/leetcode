class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) return 0;
        int n = triangle.size();
        vector<int> cur(n, INT_MAX);
        vector<int> pre(n, INT_MAX);
        cur[0] =  triangle[0][0];
        
        for(int i = 1; i < n; i++){
            pre = cur;
            cur[0] = pre[0] + triangle[i][0];
            cur[i] = pre[i - 1] + triangle[i][i];
            for(int j = 1; j < i; j++){
                cur[j] = min(pre[j - 1], pre[j]) + triangle[i][j];
            }
        }
        int minpath = INT_MAX;
        for(int i = 0; i < n; i++){
            minpath = min(minpath, cur[i]);
        }
        return minpath;
    }

    // output one possible pass
    int minimumTotal2(vector<vector<int>>& triangle) {
        if(triangle.empty()) return 0;
        int n = triangle.size();
        vector<vector<int>> DP(n, vector<int>(n,INT_MAX));
        DP[0][0] =  triangle[0][0];
        
        for(int i = 1; i < n; i++){
            DP[i][0] = DP[i-1][0] + triangle[i][0];
            DP[i][i] = DP[i - 1][i-1] + triangle[i][i];
            for(int j = 1; j < i; j++){
                DP[i][j] = min(DP[i-1][j - 1], DP[i-1][j]) + triangle[i][j];
            }
        }
        int minpath = INT_MAX;
        int idx = -1;
        for(int i = 0; i < n; i++){
            if (DP[n-1][i]<minpath) {
                minpath = DP[n-1][i];
                idx = i;
            }
        }
        vector<vector<int>> v;
        vector<int> path(n,0);
        path[n-1] = triangle[n-1][idx];

        for(int i = n-2; i >= 0; i--){
            int tmp = DP[i+1][idx] - path[i+1];
            if(idx>0&&DP[i][idx-1]==tmp){
                idx=idx-1;
            }
            path[i] = triangle[i][idx];    
        }
        for(int p:path){
            std::cout<<p<<",";
        }
        return minpath;
    }

// output all possible pass 
     int minimumTotal3(vector<vector<int>>& triangle) {
        if(triangle.empty()) return 0;
        int n = triangle.size();
        vector<vector<int>> DP(n, vector<int>(n,INT_MAX));
        DP[0][0] =  triangle[0][0];
        
        for(int i = 1; i < n; i++){
            DP[i][0] = DP[i-1][0] + triangle[i][0];
            DP[i][i] = DP[i - 1][i-1] + triangle[i][i];
            for(int j = 1; j < i; j++){
                DP[i][j] = min(DP[i-1][j - 1], DP[i-1][j]) + triangle[i][j];
            }
        }
        int minpath = INT_MAX;
        int idx = -1;
        for(int i = 0; i < n; i++){
            if (DP[n-1][i]<minpath) {
                minpath = DP[n-1][i];
                // idx = i;
            }
        }
        vector<vector<int>> ret;
        vector<int> path(n,0);
        path[0]=triangle[0][0];
            
        for(int i = 0; i < n; i++){
            if (DP[n-1][i]==minpath) {
                path[n-1] = triangle[n-1][i];
                helper(ret,path,DP,n-2,minpath-path[n-1],i,triangle);                
            }
        }
        for(auto r:ret){
            for(int p:r){
                std::cout<<p<<",";
            }
            std::cout<<std::endl;
        }
        return minpath;
    }
    void helper(vector<vector<int>>& ret,vector<int>& path,vector<vector<int>>& DP,int level,int target,int idx,vector<vector<int>>& triangle){
        if(level==0){
            ret.push_back(path);
        }
        else{
            if(idx>0&&DP[level][idx-1]==target){
                path[level] = triangle[level][idx-1];
                helper(ret,path,DP,level-1,target-triangle[level][idx-1],idx-1,triangle);
            }
            if(idx<=level&&DP[level][idx]==target){
                path[level] = triangle[level][idx];
                helper(ret,path,DP,level-1,target-triangle[level][idx],idx,triangle);   
            }
        }
    }
};

