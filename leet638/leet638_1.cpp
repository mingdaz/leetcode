class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
		int res = 0;
		int n = needs.size();
		for (int i = 0; i < n; i++) {
			res += price[i] * needs[i];
		}
		for (int i = 0; i < special.size(); i++) {
			bool ok = true;
			for (int j = 0; j < n; j++) {
				if (needs[j] < special[i][j]) ok = false;
				needs[j] -= special[i][j];
			}
			if (ok) {
				res = min(res, special[i][n] + shoppingOffers(price, special, needs));
			}
			for (int j = 0; j < n; j++) needs[j] += special[i][j];
		}
		return res;
    }
};