class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
		int index[2] = {-1,-1};
		int d = words.size();
		int ind1 = 0;
		int ind2 = 1;
		bool flag = word1==word2;
		for(int i=0;i<words.size();i++){
			if(words[i]==word1){
				index[ind1] = i;
			}
			else if(!flag&&words[i]==word2){
				index[ind2] = i;
			}
			else continue;
			if(index[ind1]>=0&&index[ind2]>=0){
				int tmp = index[ind1]>index[ind2]?index[ind1]-index[ind2]:index[ind2]-index[ind1];
				d = min(tmp,d);
			}
			if(flag) ind1^=1,ind2^=1; 
		}	
		return d;
    }
};
