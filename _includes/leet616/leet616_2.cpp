class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        vector<pair<int, int> > intervals = findInterval(s, dict);
        intervals = merge(intervals);
        for (auto it = intervals.rbegin(); it != intervals.rend(); it++) {
            s.insert(it->second, "</b>");
            s.insert(it->first, "<b>");
        }
        return s;
    }
    
private:
    vector<pair<int, int> > findInterval(string s, vector<string>& dict) {
        vector<pair<int, int> >res;
        for (auto w : dict) {
            int n = w.size();
            for (int i = 0; (i = s.find(w, i)) != string::npos; i++)
                res.push_back(make_pair(i, i + n ));
        }
        return res;
    }
    
    vector<pair<int, int> > merge(vector<pair<int, int> >& intervals) {
        vector<pair<int, int> >res;
        if (intervals.empty()) return res;
        sort(intervals.begin(), intervals.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first < b.first;
        });
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (res.back().second >= intervals[i].first) 
                res.back().second = max(res.back().second, intervals[i].second);
            else res.push_back(intervals[i]);
        }
        return res;
    }
};
