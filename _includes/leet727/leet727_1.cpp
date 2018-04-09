class Solution {
public:
    string minWindow(string S, string T) {
    string out;
    size_t p1 = 0;

    while (p1 + T.size() < S.size()) {
        size_t p2 = p1;
        bool isEnd = false;
        // forward search
        for (size_t i = 0; i < T.size(); i++) {
            while (S[p2] != T[i] && p2 < S.size()) {
                p2++;
            }
            if (p2 == S.size()) {
                isEnd = true;
                break;
            }
            p2++;
        }
        if (isEnd)
            break;
        size_t p3 = --p2;
        // backward search
        for (int i = T.size() - 1; i >= 0; i--) {
            while (S[p3] != T[i]) {
                p3--;
            }
            p3--;
        }
        p3++;
        // record the shortest answer
        if (out.empty())
            out = S.substr(p3, p2 - p3 + 1);
        else
            out = out.size() > (p2 - p3 + 1) ? S.substr(p3, p2 - p3 + 1) : out;

        p1 = p3 + 1;
    }

    return out;
    }
};