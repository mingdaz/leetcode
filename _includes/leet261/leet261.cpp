class Solution {
public:
    bool DFS(vector<vector<int> > &graph, vector<bool> &temp, vector<bool> &per, int node, int last){
        if(temp[node])return false;
        if(per[node])return true;
        temp[node]=true;
        for(int i=0;i<graph[node].size();i++){
            if(graph[node][i]==last)continue;   //avoid revisiting last node
            if(!DFS(graph,temp,per,graph[node][i],node))return false;    //cyclic
        }
        temp[node]=false;
        per[node]=true;
        return true;
    }    
    bool validTree(int n, vector<pair<int, int> >& edges) {
        //fast judgement
        if(n-1!=edges.size())return false;
        //build graph
        vector<vector<int> > graph(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i].first].push_back(edges[i].second);
            graph[edges[i].second].push_back(edges[i].first);
        }
        vector<bool> temp(n,false), per(n,false);
        if(!DFS(graph,temp,per,0,-1))return false;
        //ensure it is one connected graph
        for(int i=0;i<n;i++){
            if(!per[i])return false;
        }
        return true;
    }
};
