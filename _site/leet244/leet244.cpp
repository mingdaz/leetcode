class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for(int i=0;i<words.size();i++)
			dict[words[i]].push_back(i);
    }

    int shortest(string word1, string word2) {
        	vector<int> w1 = dict[word1];
			vector<int> w2 = dict[word2];
			int i=0,j=0;
			int d = INT_MAX;
			while(i<w1.size()&&j<w2.size()){
				int tmp;
				if(w1[i]>w2[j]){
					tmp = w1[i]-w2[j]; 
					j++;
				}
				else{
					tmp = w2[j]-w1[i];
					i++;				
				}
				if(tmp==1) return 1;
				d = min(d,tmp);
			}
			while(i<w1.size()&&w1[i]<w2[j-1]){
				int tmp = w2[j-1] - w1[i];
				d = min(d,tmp);
			}
			if(i<w1.size()){
				int tmp = w1[i] - w2[j-1];
				d = min(d,tmp);
			}
			while(j<w2.size()&&w2[j]<w1[i-1]){
				int tmp = w1[i-1] - w2[j];
				d = min(d,tmp);
			}
			if(j<w2.size()){
				int tmp = w2[j] - w1[i-1];
				d = min(d,tmp);
			}
			return d;
    }

private:
	unordered_map<string,vector<int>> dict;
};

// 60 ms
// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
