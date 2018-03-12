class Solution {
public:
int repeatedStringMatch(string a, string b) {
    vector<int> prefTable(b.size() + 1); // 1-based to avoid extra checks.
    for (auto sp = 1, pp = 0; sp < b.size(); prefTable[++sp] = pp) {
        pp = b[pp] == b[sp] ? pp + 1 :  prefTable[pp];
    }
    for (auto i = 0, j = 0; i < a.size(); i += max(1, j - prefTable[j]), j = prefTable[j]) {
        while (j < b.size() && a[(i + j) % a.size()] == b[j]) ++j;
        if (j == b.size()) return (i + j) / a.size() + ((i + j) % a.size() != 0 ? 1 : 0);
    }
    return -1;
}
};
