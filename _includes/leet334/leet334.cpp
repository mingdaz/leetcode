class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int m1=INT_MAX, m2=INT_MAX;
        for (auto x: nums){
            if(m1>=x) m1=x;
            else if(m2>=x) m2=x; 
            else return true;
        }      
       return false; 
    }
};