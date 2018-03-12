class MagicDictionary {

public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new DictNode();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto str:dict){
            DictNode* temp = root;
            for(char c:str){
                if(!temp->child[c-'a']) temp->child[c-'a'] = new DictNode();
                temp = temp->child[c-'a'];
            }
            if(!temp->child[26]) temp->child[26] = new DictNode();
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return dfs(root,false,word,0);
    }
private:
    typedef struct DictNode{
        DictNode* child[27]; 
    };
    DictNode* root;
    bool dfs(DictNode* node,bool mod,string& word, int idx){
                    
        if(!node) return false;
        if(idx==word.size()) return mod&&node->child[26];
        int key = word[idx] - 'a';
  
        if(mod){
            if(!node->child[key])
                return false;
            else
                return dfs(node->child[key],mod,word,idx+1);
        }
        else{
            for(int i=0;i<26;i++){
                if(node->child[i]){
                    if(dfs(node->child[i],i!=key,word,idx+1)) return true;   
                }   
            }
        }
        return false;
        
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
