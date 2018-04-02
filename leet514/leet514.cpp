class Solution {
public:
    int findRotateSteps(string ring, string key) {
        unordered_map<char,vector<int>> dict;
        for(int i=0;i<ring.size();i++){
            if(dict.find(ring[i])==dict.end()){
                dict[ring[i]] = vector<int>(1,i);
            }
            else{
                dict[ring[i]].push_back(i);
            }
        }
        vector<pair<int,int>> prev;
        for(int idx:dict[key[0]]){
            prev.push_back(pair<int,int>(idx,min(idx,int(ring.size()-idx))));    
        }
        for(int i=1;i<key.size();i++){
            vector<pair<int,int>> cur;            
            for(int j:dict[key[i]]){
                int op = INT_MAX;
                for(auto p:prev){
                    int k = p.first;
                    int d = abs(k - j);
                    d = min(d,int(ring.size()-d));
                    op = min(op,d+p.second);
                }
                cur.push_back(pair<int,int>(j,op));
            }
            prev = cur;
        }
        int res = INT_MAX;
        for(auto p:prev){
            res = min(res,p.second);
        }
        return res + key.size();
    }
};