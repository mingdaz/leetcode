class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
    	vector<string> res;
		if(n==2) res = {"11","69","88","96"};
		else if(n==1) res = {"0","1","8"};
		else if(n==0) ;
		else {
			vector<string> tmp = helper(n-2);
			char begin[4] = {'1','6','8','9'};
		   	char end[4] = {'1','9','8','6'};	
			for(int i=0;i<4;i++){
				for(int j=0;j<tmp.size();j++)
					res.push_back(begin[i]+tmp[j]+end[i]);
			}
		}	
		return res;
    }

	vector<string> helper(int n){
		vector<string> res;
		if(n==2) res = {"00","11","69","88","96"};
		else if(n==1) res = {"0","1","8"};
		else if(n==0) ;
		else {
			vector<string> tmp = helper(n-2);
			char begin[5] = {'0','1','6','8','9'};
		   	char end[5] = {'0','1','9','8','6'};	
			for(int i=0;i<5;i++){
				for(int j=0;j<tmp.size();j++)
					res.push_back(begin[i]+tmp[j]+end[i]);
			}
		}	
		return res;
	}
};

