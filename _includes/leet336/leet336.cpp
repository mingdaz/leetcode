class Solution {
public:
    bool ispalin(string& w, size_t l, size_t r){
        for(;l<r;l++,r--){
            if(w[l]!=w[r]) return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> ht;
        for(int i=0;i<words.size();i++){
            ht[words[i]] = i;
        }
        vector<vector<int>> ret;
        bool hasEmpty = ht.count("")>0;
        for(int i=0;i<words.size();i++){
            string w = words[i];
            int n = w.size();
            if(n==0) continue;
            if(hasEmpty&&ispalin(w,0,n-1)){
                ret.push_back({i,ht[""]});
                ret.push_back({ht[""],i});
            } 
            reverse(w.begin(),w.end());
            if(ht.count(w)>0&&ht[w]!=i){
                ret.push_back({i,ht[w]});
            }
            for(int j=0;j<n-1;j++){
                if(ispalin(w,0,j)&&ht.count(w.substr(j+1))) 
                	ret.push_back({i,ht[w.substr(j+1)]});
                if(ispalin(w,j+1,n-1)&&ht.count(w.substr(0,j+1))) 
                	ret.push_back({ht[w.substr(0,j+1)],i});
            }            
        }
        return ret;
        
    }
    
};