class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        unordered_map<int,unordered_set<int>> G;
        
        int top = org.size() + 1;        
        int head=0;
        vector<int> D(top,-1);

        for(auto s:seqs){  
            for(int i=0;i<s.size();i++){
                if(s[i]<top&&s[i]>0){
                    D[s[i]]=0;
                    if(i>0&&s[i-1]<top&&s[i-1]>0){
                        G[s[i-1]].insert(s[i]);
                    }
                }
                else return false;
            }
        }
        
        for(auto v:G){
            for(int adj:v.second){
                if(D[adj]<0) D[adj]=0;
                D[adj]++;
            }
        }
        
        for(int i=1;i<top;i++){
            if(D[i]==0){
                if(head==0) head = i;
                else return false;
            }    
        }
        
        for(int ind:org){
            if(head!=ind) return false;
            int temp=0;
            for(int adj:G[head]){
                D[adj]--;
                if(D[adj]==0){
                    if(temp>0) return false;
                    temp = adj;
                }
            }
            head = temp;
        }
        return true;
    }
};
