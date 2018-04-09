class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.empty()) return 0;
        int prev_cost[3],tmp[3];
        prev_cost[0] = costs[0][0];
		prev_cost[1] = costs[0][1];
		prev_cost[2] = costs[0][2];
		
		for(int i=1;i<costs.size();i++){	
			tmp[0] = min(prev_cost[1],prev_cost[2]) + costs[i][0];
			tmp[1] = min(prev_cost[0],prev_cost[2]) + costs[i][1];
			tmp[2] = min(prev_cost[0],prev_cost[1]) + costs[i][2];
			memcpy(prev_cost,tmp,sizeof(tmp));
		}
		return min(min(prev_cost[0],prev_cost[1]),prev_cost[2]);
    }
};
