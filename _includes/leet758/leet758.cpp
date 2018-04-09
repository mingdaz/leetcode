class Solution {
private:
    struct TrieNode {
        array<TrieNode*, 26> ch;
        bool isTerminal;
        TrieNode() : isTerminal(false) { ch.fill(nullptr);}
    };
    
    TrieNode root;
    
public:
    string boldWords(vector<string>& words, string S) {
        for (string& w : words) {
            TrieNode* curr = &root;
            for (char c : w) {
                auto next = curr->ch[c - 'a'];
                if (next == nullptr) {
                    next = curr->ch[c - 'a'] = new TrieNode();
                }
                
                curr = next;
            }
            
            curr->isTerminal = true;
        }
        
        bitset<500> bs;        
        string ret;
        for(int i = 0; i < S.size(); ++i) {
            int k = i;
            TrieNode* curr = &root;
            for(int k0 = i; k0 < S.size() && (curr = curr->ch[S[k0] - 'a']) != nullptr; ++k0) {
                if (curr->isTerminal) 
                    k = k0+1;
            }
            
            for (int j = i; j < k; ++j)
                bs.set(j);
        }
        
        bool isBold = false;
        for (int i = 0; i < S.size(); ++i) {
            if (bs[i]) {
                if(!isBold) {
                    ret += "<b>";
                    isBold = true;
                }                
            }
            else {
                if (isBold) {
                    ret += "</b>";
                    isBold = false;
                }
            }
            
            ret += S[i];
        }
        
        if(isBold)
            ret += "</b>";
        
        return ret;
    }
};

class Solution {
    
    void markBold(vector<int>& m, size_t s, size_t e)
    {
        while(s<e)
            m[s++]=1;
    }
    
public:
    string boldWords(vector<string>& words, string S) {
        
        vector<int> m(S.size(),0);
        
        for(auto& w: words)
        {
            size_t f=S.find(w);
            while(f!=string::npos)
            {
                markBold(m,f,f+w.size());
                f=S.find(w,f+1);
            }
        }
        
        bool open=false;
        string res;
        for(int i=0;i<S.size();i++)
        {
            if(m[i]==0)
            {
                if(open)
                {
                    res+="</b>";
                    open=false;
                }
                    
                
                res+=S[i];
            }
            else 
            {
                if(!open)
                {
                    res+="<b>";
                    open=true;
                }
                    
                res+=S[i];
            }
        }
        
        if(open)
        {
            res+="</b>";
        } 
        
        return res;
        
    }
};