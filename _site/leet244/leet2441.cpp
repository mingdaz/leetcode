class WordDistance {

    unordered_map<string,vector<int>> word_indices;

public:
    WordDistance(vector<string>& words) {
        for(int i=0; i<words.size(); ++i) 
            word_indices[words[i]].push_back(i);
    }

    int shortest(string word1, string word2) {
        vector<int>& idx1 = word_indices[word1];
        vector<int>& idx2 = word_indices[word2];
        int min_dist = INT_MAX;
        for(int d1 : idx1) {
            int begin = 0;
            int end = idx2.size()-1;
            int cur_dist = INT_MAX;
            while(begin <= end) {
                int mid = begin + (end - begin) / 2;
                cur_dist = min(cur_dist, abs(idx2[mid]-d1));
                if(d1 > idx2[mid]) begin = mid+1;
                else end = mid-1;
            }
            min_dist = min(min_dist, cur_dist);
        }
        return min_dist;
    }
};

//48 ms
