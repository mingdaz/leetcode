class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(1001, 0);
        for (int i = 1; i!=parent.size();++i){
            parent[i] = i;
        }
        for (auto e : edges){
            if (unionFind(parent, e[0]) == unionFind(parent, e[1])) return e;
            parent[unionFind(parent,e[1])] = unionFind(parent,e[0]);
        }
        return {0,0};
    }
    
    int unionFind(vector<int> & p, int t){
        if (t!=p[t])
            p[t] = unionFind(p,p[t]);
        return p[t];
    }
};
