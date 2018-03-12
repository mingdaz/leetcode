class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        map<int, int> mp;
        for (auto& transaction : transactions) {
            mp[transaction[0]] += transaction[2];
            mp[transaction[1]] -= transaction[2];
        }
        vector<int> lend, borrow;
        for (auto& m : mp) {
            if (m.second < 0) borrow.push_back(-m.second);
            else if (m.second > 0) lend.push_back(m.second);
        }
        if (borrow.empty() && lend.empty()) return 0;
        int min_res = transactions.size();
        for (int loop = 0; loop < lend.size(); loop++) {
            int res = 0;
            int lend_left = 0, borrow_left = 0;            
            int i = 0, j = 0;
	    	while (i < lend.size() && j < borrow.size()) {
				lend_left = lend_left != 0 ? lend_left : lend[(i+loop)%lend.size()];
				borrow_left = borrow_left != 0 ? borrow_left : borrow[j];
				if (lend_left == borrow_left) {
	            	i++;
		    		j++;
		    		lend_left = 0;
		    		borrow_left = 0;
				} 
				else if (lend_left < borrow_left) {
		    		borrow_left = borrow_left - lend_left;
		    		i++;
		    		lend_left = 0;
	        	} 
	        	else {
		    		lend_left = lend_left - borrow_left;
		    		j++;
		    		borrow_left = 0;
				}
				res++;
            }
            min_res = min(min_res, res);
        }
        return min_res;
    }
};
