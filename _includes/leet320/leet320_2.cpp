
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> abbrs;
        abbrs.push_back("");
        
        for (int i = 0; i < word.length(); i++) {
            int t = abbrs.size();
            for (int j = 0; j < t; j++) {
                string cur = abbrs[j];
                abbrs[j] += word[i];
                
                int index = cur.length() - 1;
                while (index >= 0 && isdigit(cur[index])) index--;
                if (index < (int)cur.length() - 1) {
                    abbrs.push_back(cur.substr(0, index + 1) + to_string(stoi(cur.substr(index + 1)) + 1));
                } else {
                    abbrs.push_back(cur + '1');
                }
            }
        }
        
        return abbrs;
    }
};
