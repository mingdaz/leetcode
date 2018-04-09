class Solution {    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto idxCmp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first>=p2.first;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(idxCmp)> Q(idxCmp);
        for(int i=0;i<wordDict.size();i++){
            int idx = s.find(wordDict[i]);
            if(idx!=string::npos){
                Q.push(pair<int,int>(idx,i));
            }
        }
        priority_queue<int,vector<int>, greater<int>> ind_pq;
        ind_pq.push(0);
        while(!ind_pq.empty()){
            int tmp = ind_pq.top();
            if(tmp==s.size()) return true;
            ind_pq.pop();
            // std::cout<<tmp<<"q.size:"<<Q.size()<<std::endl;
            while(!Q.empty()){
                auto p = Q.top();
                // std::cout<<"p.first:"<<p.first<<std::endl;
                
                if(p.first==tmp){
                    Q.pop();
                    ind_pq.push(tmp + wordDict[p.second].size());
                    // std::cout<<tmp<<std::endl;
                    int idx = s.find(wordDict[p.second],p.first + 1);
                    if(idx!=string::npos){
                        p.first = idx;
                        Q.push(p);
                    }
                }
                else if(p.first<tmp){
                    Q.pop();
                    int idx = s.find(wordDict[p.second],p.first + 1);
                    if(idx!=string::npos){
                        p.first = idx;
                        Q.push(p);
                    }
                }
                else 
                    break;
            }
        }
        
        return false;
    }
    
        
};