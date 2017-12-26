class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        helper(word, 0, "", 0, result);
        return result;
    }
    void helper(string word, int pos, string current, int count, vector<string>& result){
        if (pos == word.length()) {
            if (count > 0) result.push_back(current + to_string(count));
            else result.push_back(current);
        }
        else{
            helper(word, pos+1, current, count+1, result);
            if (count > 0) helper(word, pos+1, current + to_string(count) + word[pos], 0, result);
            else helper(word, pos+1, current + word[pos], 0, result);
        }
    }
};
