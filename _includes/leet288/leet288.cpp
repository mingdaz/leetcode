class ValidWordAbbr {
private: 
    unordered_map<int,string> dict[128][128];
public:
    ValidWordAbbr(vector<string> dictionary) {
        for(auto str:dictionary){
            int n = str.length();
            auto it = dict[str[0]][str[n-1]].find(n);
            if(it != dict[str[0]][str[n-1]].end() && dict[str[0]][str[n-1]][n] != str)
                dict[str[0]][str[n-1]][n] = "";
            else 
                dict[str[0]][str[n-1]][n] = str;
        }
    }
    
    bool isUnique(string str) {
        int n = str.length();
        auto it = dict[str[0]][str[n-1]].find(n);
        if(it!=dict[str[0]][str[n-1]].end())
            return dict[str[0]][str[n-1]][n]==str;
        return true;
        
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */
