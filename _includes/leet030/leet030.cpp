class Solution {
 public:
  typedef vector<int> FingerPrint;

  vector<int> findSubstring(const string str, const vector<string>& dict) {
    vector<int> ret;
    word_len_ = dict[0].size();
    char_size_ = dict.size() * word_len_; 

    if (str.size() < char_size_) {
      return ret;
    }

    dict_.clear();
    for (auto &w: dict) {
      dict_[w] += 1;
    }

    fp_ = gen_fingerprint();
    decltype(fp_) lfp(word_len_, 0);
    for (int p = 0; p < char_size_; ++p) {
      lfp[p % word_len_] += str[p];
    }
    if (equal(lfp, 0) && check(str, 0)) {
      ret.push_back(0);
    }

    for (int p = char_size_; p < str.size(); ++p) {
      lfp[(p) % word_len_] += -str[p - char_size_] + str[p];
      if (equal(lfp, p + 1) && check(str, p + 1 - char_size_)) {
        ret.push_back(p + 1 - char_size_);
      }
    }

    return ret;
  }

 protected:
  bool equal(const FingerPrint &fp, int start) {
    for (int p = 0; p < word_len_; ++p) {
      if (fp[(start + p) % word_len_] != fp_[p]) {
        return false;
      }
    }
    return true;
  }

  bool check(const string &str, int p) {
    map<string, int> freqs; 
    for (int d = p; d < p + char_size_; d += word_len_) {
      string substr = str.substr(d, word_len_);
      freqs[substr] += 1;
    }

    auto ite1 = freqs.begin(), ite2 = dict_.begin();
    while (ite1 != freqs.end() && ite2 != freqs.end()) {
      if (ite1->first == ite2->first && ite1->second == ite2->second) {
        ++ite1;
        ++ite2;
        continue;
      }
      return false;
    }

    return true;
  }

  FingerPrint gen_fingerprint() {
    FingerPrint ret(word_len_, 0);
    for (auto &pair: dict_) {
      for (int p = 0; p < word_len_; ++p) {
        ret[p] += pair.first[p] * pair.second;
      }
    }

    return ret;
  }

  map<string, int> dict_;
  int char_size_, word_len_;
  FingerPrint fp_;
};
