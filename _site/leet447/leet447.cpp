class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        for(int i = 0; i < points.size(); i++){
            unordered_map<int,int> mymap;
            for(int j = 0; j < points.size(); j++){
                if(i!=j){
                    mymap[pow(points[i].first-points[j].first,2) + 
                          pow(points[i].second-points[j].second,2) ]++;
                }    
            }
            for(auto it:mymap){
                int temp = it.second;
                res += (temp*(temp-1));
            }
        }
        return res;
    }
};
