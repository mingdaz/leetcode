class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        
        vector<int> vec[n+1];
        int degree[n+1];
        
        for(int i=0;i<=n;i++)
            degree[i]=0;
        
        for(int i=0;i<n-1;i++){
        int a=edges[i].first;
        int b=edges[i].second;
            
            vec[a].push_back(b);
            vec[b].push_back(a);
            degree[a]++;
            degree[b]++;
        }
        
        queue<int >qq;
        for(int i=0;i<n;i++)
            if(degree[i]==1)
                qq.push(i);
        
        while(n>2){
            int sz=qq.size();
            for(int i=0;i<sz;i++){
                int temp=qq.front();//cout<<temp<<" ";
                qq.pop();
                n--;
                
                for(auto j=vec[temp].begin();j!=vec[temp].end();j++){
                    degree[*j]--;
                    if(degree[*j]==1)
                    qq.push(*j);
                }
            }
        }
        vector<int> rs;
        if(qq.empty()){rs.push_back(0);return rs;}
        
        while(!qq.empty()){
            rs.push_back(qq.front());
            qq.pop();
        }
        return rs;
    }
};
