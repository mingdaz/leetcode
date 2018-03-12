class Solution {
 	vector<vector<int>> res;
	vector<int> ans;	
public:
    vector<vector<int>> getFactors(int n) {
		for(int i=2;i*i<=n;i++){
			if(n%i==0){
				ans.push_back(i);
				factor(n/i,i);
				ans.pop_back();
			}
		}
		return res;
	}

	void factor(int n,int minval){
		for(int i=minval;i*i<=n;i++){
			if(n%i==0){
				ans.push_back(i);
				factor(n/i,i);
				ans.pop_back();
			}
		}
		ans.push_back(n);
		res.push_back(ans);
		ans.pop_back();
	}
};

