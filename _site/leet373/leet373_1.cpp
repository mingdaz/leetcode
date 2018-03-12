class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const vector<int>& lhs, const vector<int>&rhs) const
  {
    if (reverse) return (lhs[0]<=rhs[0]);
    else return (lhs[0]>rhs[0]);
  }
};


class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> ret;
        if(nums1.empty()||nums2.empty()) return ret;
        vector<vector<char>> hp(nums1.size(),vector<char>(nums2.size(),0));
        priority_queue<vector<int>,std::vector<vector<int>>,mycomparison> sum;
        sum.push({nums1[0]+nums2[0],0,0});
        hp[0][0] = 1;
        while(!sum.empty()&&ret.size()<k){
            vector<int> tmp = sum.top();
            sum.pop();
            ret.push_back(pair<int,int>(nums1[tmp[1]],nums2[tmp[2]]));
            // std::cout<<tmp[1]<<";"<<tmp[2]<<std::endl;
            if(tmp[1]+1<nums1.size()&&hp[tmp[1]+1][tmp[2]]==0){
                sum.push({nums1[tmp[1]+1]+nums2[tmp[2]],tmp[1]+1,tmp[2]});  
                hp[tmp[1]+1][tmp[2]]=1;
            } 
            if(tmp[2]+1<nums2.size()&&hp[tmp[1]][tmp[2]+1]==0){
                sum.push({nums1[tmp[1]]+nums2[tmp[2]+1],tmp[1],tmp[2]+1}); 
                hp[tmp[1]][tmp[2]+1]=1;
            } 
        }
        return ret;
    }
};