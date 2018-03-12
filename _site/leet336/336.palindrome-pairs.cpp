class Solution {
public:
	bool isPalin(string& w, int i1, int i2) {
		for (; i1 < i2; i1++, i2--)
			if (w[i1] != w[i2]) return false;
		return true;
	}
    vector<vector<int>> palindromePairs(vector<string>& words) {
		unordered_map<string, int> ht;
		for (int i=0; i < words.size(); i++) ht[words[i]] = i;
		vector<vector<int>> ret;
		for (int i=0; i < words.size(); i++) {
			auto w=words[i];
			reverse(w.begin(), w.end());
			int n=w.size();
			// current word and its mirror 
			if (ht.count(w) && ht[w] != i) { ret.push_back({ht[w], i});  }
			// itself is an palindrome then find the index of empty string
			if (n && isPalin(w, 0, n-1) && ht.count("")) { ret.push_back({i, ht[""]}); ret.push_back({ht[""], i});}
			for (int l=1; l < n; l++) {
				// for different substring if it is plaindrome find corresponding pair
				if (isPalin(w, 0, n-l-1) && ht.count(w.substr(n-l)) && ht[w.substr(n-l)]!=i) ret.push_back({i, ht[w.substr(n-l)]});
				if (isPalin(w, l, n-1) && ht.count(w.substr(0, l)) && ht[w.substr(0, l)] != i) ret.push_back({ht[w.substr(0, l)], i});
			}
		}
		return ret;
    }
};
