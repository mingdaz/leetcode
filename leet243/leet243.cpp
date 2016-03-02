class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
    	int ind1 = -1,ind2 = -1;
		int dis = INT_MAX;
		for(int i=0;i<words.size();i++){
			if(words[i]==word1) ind1=i;
			else if(words[i]==word2) ind2=i;
			else continue;
			if(ind1<0||ind2<0) continue;
			int tmp = ind1>ind2?ind1-ind2:ind2-ind1;
			dis = min(dis,tmp);
		}
		return dis;
    }
};

