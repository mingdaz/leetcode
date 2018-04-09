class Solution {
public:
    int findLUSlength(string a, string b) {
        return a.compare(b) ?   max(a.length(), b.length()):-1;
    }
};
