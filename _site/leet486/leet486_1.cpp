class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return helper(nums,0,0,0,nums.size(),0);
    }
    
    bool helper(vector<int>& nums, int p1, int p2, int l, int r,int turn){
        if(l==r) return p1>=p2;
        if(turn==0){
            if(helper(nums,p1+nums[l],p2,l+1,r,1)) return true;
            if(helper(nums,p1+nums[r-1],p2,l,r-1,1)) return true;        
        }
        else{
            if(helper(nums,p1,p2+nums[l],l+1,r,0)
               &&helper(nums,p1,p2+nums[r-1],l,r-1,0)) return true;        
        }
        return false;
    }
};