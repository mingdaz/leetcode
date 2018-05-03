class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> prices(n, vector<int>(n, -1));
        unordered_map<int, vector<int>> edges;
        for(int i = 0; i < flights.size(); i ++) {
            prices[flights[i][0]][flights[i][1]] = flights[i][2];
            //degrees[flights[0]][flights[1]] = 1;
            edges[flights[i][0]].push_back(flights[i][1]);
        }
        for(int i = 0; i < n; i ++) {
            prices[i][i] = 0;
            //degrees[i][i] = 0;
        }
        queue<pair<int, int>> dests;
        dests.push(make_pair(src, 0));
        int minPrice = prices[src][dst];
        for(int i = 0; i <= K; i++) {
            int size = dests.size();
            for(int j = 0; j < size; j++) {
                int from = dests.front().first, price = dests.front().second;
                dests.pop();
                for(auto to : edges[from]) {
                    //cout << "stop: " << i + 1 << ", from: " << from << ", to: " << to << ", src-from price: " << price << ", src-to price: " << price + prices[from][to] << ", from-to least price: " << prices[from][to] << ", src-dst least price: " << minPrice << endl;
                    if (to != dst) {
                        if ((price + prices[from][to] < prices[src][to] || prices[src][to] == -1 || from == src) &&
                            (price + prices[from][to] < minPrice || minPrice == -1))
                            dests.push(make_pair(to, price + prices[from][to]));
                        if (prices[src][to] == -1) {
                            prices[src][to] = price + prices[from][to];
                        }
                    } else {
                        if (minPrice == -1) minPrice = price + prices[from][to];
                        minPrice = min(minPrice, price + prices[from][to]);
                    }
                }
            }
        }
        return minPrice;
    }
};