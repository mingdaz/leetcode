class Solution {
public:
    unordered_map<string,unordered_set<string>>parent;
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>>res;
        unordered_set<string>wordlist(wordList.begin(), wordList.end());
        if(wordlist.find(endWord) == wordlist.end()) return res;
        
        unordered_set<string>head, tail, *phead, *ptail;
        bool got = false, isbegin = true;
        head.insert(beginWord); tail.insert(endWord);
        
        while(head.size()>0 && tail.size()>0 && !got){
           if(head.size()<=tail.size()){
               phead = &head;
               ptail = &tail;
               isbegin = true;
           }else{
               phead = &tail;
               ptail = &head;
               isbegin = false;
           }
            unordered_set<string>next;
            
            for(auto i= ptail->begin();i!=ptail->end();i++)
                wordlist.erase(*i);
            for(auto j= phead->begin();j!=phead->end();j++)
                wordlist.erase(*j);
            
            for(auto now = phead->begin();now!= phead->end();now++){
                string top = *now;  
                for(auto itr = top.begin();itr!=top.end();itr++){
                    char ch = *(itr);
                    for(int j = 0; j<26; j++){
                        *(itr) = 'a'+j;
                        if(*(itr)!=ch && ptail->find(top) != ptail->end()) {
                            got = true;
                            isbegin ? parent[top].insert(*(now)) : parent[*(now)].insert(top);
                        }
                        else if(*(itr)!=ch && wordlist.find(top)!=wordlist.end()){
                            isbegin ? parent[top].insert(*(now)) : parent[*(now)].insert(top);                
                            next.insert(top);
                        }
                    }
                    *itr = ch;
                }
            }
            *phead = next;
        }
        if(got) {
            vector<string>cur={endWord};
            getPath(res,cur,beginWord,endWord);
        }
        return res;
    }
    
    void getPath(vector<vector<string>>& res, vector<string>& cur, const string& beginWord, string curword){
        if(curword == beginWord){
            reverse(cur.begin(),cur.end());
            res.push_back(cur);
            reverse(cur.begin(),cur.end());
            return;
        }
        for(auto itr: parent[curword]){
            cur.push_back(itr);
            getPath(res,cur,beginWord,itr);
            cur.pop_back();
        }
    }
};