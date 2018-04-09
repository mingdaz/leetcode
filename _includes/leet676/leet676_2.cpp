class MagicDictionary {
public:
    vector<string> dict;
    /** Initialize your data structure here. */
    MagicDictionary() {
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        this->dict = dict;
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for(string str:dict){
            if(judge(str,word)) return true;
        }
        return false;
    }
    
    bool judge(string str, string word){
        if(str.length() != word.length()) return false;
        int count = 0;
        for(int i=0; i<str.length(); i++){
            if(str[i] != word[i]) count++;
        }
        return count == 1? true: false;
    }
};
