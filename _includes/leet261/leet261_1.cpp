class Solution {
private:
    vector<int> UF;
    int helper(int u){
        while(UF[u]!=u) u = UF[u];
        return u;
    }
    
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        int group = n;
        UF = vector<int>(n);
        for(int i=0;i<n;i++){
            UF[i] = i;
        }
        for(auto p:edges){
            int u = helper(p.first);
            int v = helper(p.second);
            if(u==v) return false;
            else {
                UF[u] = v;
                group --;
            }
        }
        return group==1;
    }
};
