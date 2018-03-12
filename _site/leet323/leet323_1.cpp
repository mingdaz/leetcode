class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        int ret = n;
        vector<int> UF(n,0);
        for(int i=0;i<n;i++){
            UF[i] = i;
        }
        for(auto p:edges){
            int ra = helper(p.first,UF);
            int rb = helper(p.second,UF);
            if(ra!=rb){
                UF[ra] = rb;
                ret --;
            }
        }
        return ret;
    }
    int helper(int node,vector<int> & UF){
        while(UF[node]!=node){
            node = UF[node];
        }
        return node;
    }
};
