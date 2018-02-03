class myComparator
{
public:
    int operator() (const pair<int,int>& p1, pair<int,int>& p2)
    {
        return p1.first > p2.first;
    }
};

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        priority_queue <pair<int,int>, vector<pair<int,int>>, myComparator > pq;   
        string ret = "";
        size_t idx=0,tmp,starter;
        int i;
        
        for(i=0;i<dict.size();i++){
            tmp = s.find(dict[i]); 
            if(tmp!=string::npos){
                pq.push(pair<int,int>(tmp,i));
            }
        }
//         pair first match position
//         pair second string index
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            
            starter = p.first;
            i =  p.second;
                
            tmp = s.find(dict[i],starter+1); 
            if(tmp!=string::npos){
                p.first = tmp;
                pq.push(p);
            }
            
            ret = ret + s.substr(idx,starter-idx) + "<b>";
            idx = starter + dict[i].size();
            
            while(!pq.empty()){
                auto q = pq.top();
                if(q.first <= idx){
                    pq.pop();
                    idx = max(idx,q.first + dict[q.second].size());
                    tmp = s.find(dict[q.second],q.first+1); 
                    if(tmp!=string::npos){
                        q.first = tmp;
                        pq.push(q);
                    }
                }
                else{
                    break;
                }
            }
            ret = ret + s.substr(starter,idx-starter) + "</b>"; 
            
        }
        if(idx<s.size()){
            ret = ret + s.substr(idx);
        }
            
        return ret;
    }
};

