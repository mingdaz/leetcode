class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& p) {
        //vector<pair<int, int>> p = people;
        int n = p.size();

        sort(p.begin(), p.end(), _comp);
        
        vector<pair<int, int>> res;
        
        for (int i = 0;i < n;i++) {
            res.insert(res.begin()+p[i].second, p[i]);
        }
        return res;
    }

private:
    static bool _comp(pair<int,int>& left, pair<int,int>& right) {
        if (left.first > right.first) {
            return true;
        }
        if (left.first < right.first) {
            return false;
        }
        
        return left.second < right.second;
    }
};