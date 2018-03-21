class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        priority_queue<pair<int,int>> Q;
        for(int num:nums){
            map[num]--;
        }
        for(auto it = map.begin();it!=map.end();++it){
            
            if(Q.size()<k){
            	Q.push(pair<int,int>(it->second,it->first));
            }
            else{
            	auto p = Q.top();
                if(p.first>it->second){
                    Q.pop();
                    Q.push(pair<int,int>(it->second,it->first));
                }                
            }
        }
        vector<int> res;
        while(!Q.empty()){
            res.push_back(Q.top().second);
            Q.pop();
        }
        return res;
    }
};

// time complexity: O(n) + O(k+(n-k)logn) = O(n+k+nlogn - klogn)