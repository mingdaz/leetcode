class Solution {
public:
    
    bool valid(double a, double b){
        if(abs((a+b)- 24.0) < 0.0001)
            return true;
        
        if(abs((a-b)- 24.0) < 0.0001)
            return true;
        
        if(abs((a*b)- 24.0) < 0.0001)
            return true;
        
        // to avoid devision by zero
        if(b && abs((a/b)- 24.0) < 0.0001)
            return true;
        
        return false;
    }
    
    bool valid(double a, double b, double c){
        
        if(valid(a+b, c) || valid(a-b, c) || valid(a*b, c) || b && valid(a/b, c))
            return true;
        
        if(valid(a, b+c) || valid(a, b-c) || valid(a, b*c) || c && valid(a, b/c))
            return true;
        
        return false;
    }
    
    bool isvalid(vector<int>& nums){
        double a = nums[0];
        double b = nums[1];
        double c = nums[2];
        double d = nums[3];
        
        if(valid(a+b, c, d) || valid(a-b, c, d) || valid(a*b, c, d) || b && valid(a/b, c, d))
            return true;
        
        if(valid(a, b+c, d) || valid(a, b-c, d) || valid(a, b*c, d) || c && valid(a, b/c, d))
            return true;
        
        if(valid(a, b, c+d) || valid(a, b, c-d) || valid(a, b, c*d) || d && valid(a, b, c/d))
            return true;
        
        return false;
    }
    
    bool judgePoint24(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        // Try each permutation of nums and see it it is possible ot get or not.
        do{
            if(isvalid(nums))
                return true;
        }while(next_permutation(nums.begin(), nums.end()));
        
        return false;
    }
};