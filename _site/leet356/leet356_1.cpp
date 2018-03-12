class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        unordered_map<int,set<int>> dict;
        for(auto p:points){
            dict[p.second].insert(p.first);
        }
        float c;
        bool flag = false;
        for(auto s:dict){
            auto ms = s.second;
            int i = 0;
            int j = ms.size()-1;
            auto a = ms.begin();
            auto b=ms.crbegin();
            for(;i<=j;++a,++b,++i,--j){
                float temp = (*a+*b)/2.0;
                // std::cout<<temp<<std::endl;
                if(flag) {
                    if(temp!=c) return false;
                }
                else {
                    flag = true;
                    c = temp;
                }
            }
        }
        return true;
    }
};
