class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* temp = root;
        for(char c:word){
            int key = c-'a';
            if(!temp->p[key]) temp->p[key] = new Node();
            temp = temp->p[key];
        }
        if(!temp->p[26]) temp->p[26] = new Node();
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* temp = root;
        for(char c:word){
            int key = c-'a';
            if(!temp->p[key]) return false;
            temp = temp->p[key];
        }
        return temp->p[26];
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* temp = root;
        for(char c:prefix){
            int key = c-'a';
            if(!temp->p[key]) return false;
            temp = temp->p[key];
        }
        return true;
    }
    
private:
    typedef struct Node{
        Node* p[27];
    };
    Node* root;
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
