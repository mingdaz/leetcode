class Solution {
public:
    void getPermutation(vector<vector<int>>& ans, vector<int> nums, int index) {
        if(index+1 == nums.size()){
            ans.push_back(nums);
            return;  
        } 
        for(int i=index;i<nums.size();i++){
            if(i!=index && nums[i]==nums[index]) continue;
            swap(nums[index],nums[i]);
            getPermutation(ans,nums,index+1);  
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        getPermutation(ans, nums, 0);
        return ans;
    }
};

class Solution2 {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        std::sort(nums.begin(),nums.end());
        res.push_back(nums);
        int size = nums.size();
        int k,i,j,l;
        while(true){
            k=-1;
            i=size-1;
            while(i>0){
                if(nums[i-1]<nums[i]){
                    k=i-1;
                    i=0;
                }
                i--;
            }    
            if(k==-1) break;
            j = size-1;
            while(j>k){
                if(nums[j]>nums[k]){
                    l = j;
                    j=k;
                }
                j--;
            }
            swap(nums[k],nums[l]);
            k++;
            reverse(nums.begin()+k,nums.end());
            res.push_back(nums);
        }
        return res;
        
    }
};