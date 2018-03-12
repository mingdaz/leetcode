class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Method 1: Recursive solution:
        // Basically we have to check for the characters/group of characters from left and keep checking if 
        // these can be found in the dictionalry.
        // For the recursion we start from the last element and try to see if the other bunches can be made or not.
        vector<int> mem(s.length(), -1);
        
        // Convert the wordDict to set.
        unordered_set<string> wordSet;
        for (auto a : wordDict) {
            wordSet.insert(a);
        }
        
        return checkWordBreak(s, 0, mem, wordSet);
        
        //return true;
    }
    
    bool checkWordBreak(string s, int startIdx, vector<int> &mem, unordered_set<string> &wordSet) {
        if (startIdx >= s.length()) {
            return true;
        }
        
        if (mem[startIdx] != -1) {
            return mem[startIdx];
        }
        
        for (int i = startIdx; i < s.length(); i++) {
            // The conditions are:
            // if s[start] is present in the set and checkWordBreak(from start+1) returns true, it is true.
            // Else, we check for s.substr[start,1] and same for checkWordBreak(from start+2) and so on.
            string sub = s.substr(startIdx, i-startIdx+1);
            if (wordSet.count(sub) != 0 && checkWordBreak(s, i+1, mem, wordSet)) {
                mem[startIdx] = 1;
                return true;
            }
        }
        mem[startIdx] = 0;
        return false;
    }
};