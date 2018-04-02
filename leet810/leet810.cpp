class Solution {
public:
    bool xorGame(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt = 0;
        int i,j;
        for(i=0;i<nums.size();i++){
            for(j=i+1;nums[i]==nums[j]&&j<nums.size();j++);
            if((j-i)%2==1) cnt++;
            i=j-1;
        }
        return cnt%2==0;
        
    }
};