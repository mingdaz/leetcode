class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if(words1.size()!=words2.size()) return false;
        
        int ind = 1;
        for(auto p:pairs){
            if(dict[p.first]==0) dict[p.first] = ind++;
            if(dict[p.second]==0) dict[p.second] = ind++;
        }
        UF = vector<int>(ind,0);
        for(int i=0;i<ind;i++){
            UF[i] = i;
        }
        for(auto p:pairs){
            Union(p.first,p.second);    
        }
        
        for(int i=0;i<words1.size();i++){
            if(find(words1[i]) != find(words2[i]) ) return false;
        }
        return true;
    }
private:
    unordered_map<string,int> dict;
    vector<int> UF;
    int find(string& p){
        int ind = dict[p];
        while(ind != UF[ind]){
            ind = UF[ind];
        }
        return ind;
    }
    void Union(string& p, string& q){
        int qRoot = find(q);
        int pRoot = find(p);
        if(pRoot==qRoot) return;
        UF[pRoot] = qRoot;
    }
};
