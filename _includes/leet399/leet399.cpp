class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string,unordered_map<string, double>> graph;
        vector<double> res(queries.size(),-1);
        for(int i=0;i<equations.size();i++){
            graph[equations[i].first][equations[i].second] = values[i];
            if(values[i]!=0){
                graph[equations[i].second][equations[i].first] = 1.0/values[i];    
            }
        }
        for(int i=0;i<queries.size();i++){
            if(graph.find(queries[i].first)!=graph.end()&&
              graph.find(queries[i].second)!=graph.end()){
                unordered_set<string> visit;
                res[i]=dfs(graph,queries[i].first,queries[i].second,visit);
            }
        }
        return res;
    }
    
private:
    double dfs(unordered_map<string,unordered_map<string, double>>& graph, const string& a, const string& b, unordered_set<string>& visit){
        if(graph.find(a)==graph.end())
            return -1.0;
        if(visit.find(a)!=visit.end())
            return -1.0;
        if(a==b)
            return 1.0;
        if(graph[a].find(b)!=graph[a].end()){
            return graph[a][b];
        }
        visit.insert(a);
        for(auto it = graph[a].begin();it!=graph[a].end();++it){
            double val = dfs(graph,it->first,b,visit);
            if(val!=-1)
                return it->second*val;     
        }
        return -1;
    }
};