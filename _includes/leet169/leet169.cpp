class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        int k = 0;
        int res;
        for(int i=0;i<size;i++){
            if(k==0){
                k++;
                res = nums[i];
            }
            else{
                if(nums[i]==res)
                    k++;
                else
                    k--;
            }
        }
        return res;
    }
};