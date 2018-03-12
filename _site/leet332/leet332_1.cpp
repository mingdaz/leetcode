class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        //the reason to use multiset instead of unordered_set or set is because it allows duplicates and automatically sorted
        unordered_map<string, multiset<string>> map;
        vector<string> ret;
        if(tickets.empty()) return ret;
        
        for(auto a : tickets)
            map[a.first].insert(a.second);
        stack<string> dfs;
        
        dfs.push("JFK");
        while(!dfs.empty()){
            string curr = dfs.top();
            if(map[curr].empty()){
                ret.push_back(curr);
                dfs.pop();
            } else {
                dfs.push(*map[curr].begin());
                map[curr].erase(map[curr].begin());
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
