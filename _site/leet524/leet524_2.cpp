class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {   
        string ret = "";
        for(auto word : d) {
            int pos = 0;
            bool flag = true;
            for(char c : word) {
                pos = s.find(c, pos);
                if (pos == string::npos) {
                    flag = false;
                    break;
                }
                pos++;
            }
            
            if (flag) {
                if (word.size() > ret.size()) ret = word;
                else if (word.size() == ret.size()) {
                    if (lexicographical_compare(word.begin(), word.end(), ret.begin(), ret.end())) {
                        ret = word;
                    }
                }
            }
        }
        return ret;
    }
};
