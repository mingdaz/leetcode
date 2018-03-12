class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> ret;
        vector<int> UF(m*n,-1);
        vector<vector<int>> d = {{-1,0},{1,0},{0,-1},{0,1}}; 
        int cnt = 0;
        for(int i=0;i<positions.size();i++){
            int idx = positions[i].first*n+positions[i].second;
            for(int j=0;j<4;j++){
                int x = positions[i].first + d[j][0];
                int y = positions[i].second + d[j][1];
                if(x>=0&&x<m&&y>=0&&y<n){
                    int tmp = x*n+y;
                    int root = find(UF,tmp);
                    if(root!=-1){
                        if(UF[idx]==-1){
                            UF[idx] = root;
                        }
                        else if(root!=UF[idx]){
                            UF[root]=UF[idx];
                            cnt--;
                        }
                    }
                }
            }
            if(UF[idx]==-1){
                cnt++;
                UF[idx] = idx;
            }
            ret.push_back(cnt);
        }
        return ret;
    }
    
private:
    int find(vector<int>& UF, int idx){
        if(UF[idx]==-1) return -1;
        while(UF[idx]!=idx) idx = UF[idx];
        return idx;
    }
};