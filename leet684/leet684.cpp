class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,int> G;
        for(vector<int> e:edges){
            int p = -1,q = -1;
            if(G.find(e[0])!=G.end()){
                p = G[e[0]];
                while(p!=G[p]) p = G[p];
            }
            if(G.find(e[1])!=G.end()){
                q = G[e[1]];
                while(q != G[q]) q = G[q];
            }
                
            if(p<0&&q<0){
                G[e[0]] = G[e[1]] = e[0];
            }
            else if(q<0&&p>0) G[e[1]] = p;
            else if(p<0&&q>0) G[e[0]] = q;
            else if(p!=q) G[p] = q;
            else return e;
        }
        return {};
    }
};
