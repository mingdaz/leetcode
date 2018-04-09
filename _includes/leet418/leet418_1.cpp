class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int sentence_len = sentence[0].size();
        for (auto it = sentence.begin() + 1; it != sentence.end(); ++it) {
            sentence_len += it->size() + 1;
        }

        std::vector<int> reps(sentence.size());
        std::vector<int> next(sentence.size());
        int rep = cols - sentence_len;
        int rest;
        if (rep < 0) {
            rep = 0;
            rest = cols + 1; // +1 to compensate the -= +1 in for-loop
        }
        else {
            rest = 0;
            if (rep % (sentence_len + 1) == 0)
                ++rest;
            rep = rep / (sentence_len + 1) + 1;
            rest += cols - (sentence_len + 1) * rep + 1;
        }

        int start = -1;
        for (int m = 0; m < sentence.size(); ++m) {
            while (rest >= 0) {
                if (start == sentence.size() - 1)
                    ++rep;
                start = (start + 1) % sentence.size();
                rest -= sentence[start].size() + 1;
            }
            reps[m] = rep;
            next[m] = start;
            // prepare next loop
            rest += sentence[m].size() + 1;
            if (m == sentence.size() - 1)
                --rep;
        }

        int r;
        std::vector<int> rep_hist;
        start = 0;
        rep = 0;

        for (r = 0; r < rows; ++r) {
            rep += reps[start];
            rep_hist.push_back(rep);
            start = next[start];
            if (start == 0) {  // rows repeated
                ++r;
                break;
            }
        }

        rest = rows % r;
        if (rest > 0)
            rest = rep_hist[rest - 1];

        return (rows / r) * rep + rest;
    }
};
