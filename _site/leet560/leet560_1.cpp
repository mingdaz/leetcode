// brute force
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n,0);
        int temp =0;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            temp += nums[i];
            sum[i] = temp;
            if(temp==k)
                cnt++;
            for(int j=0;j<i;j++){
                if(sum[i] - sum[j]==k)
                    cnt++;
            }
        }
        return cnt;
    }
};
