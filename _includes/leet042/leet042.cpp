class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        if(right < 2) return 0;
        int leftMax = height[left] , rightMax = height[right], second;
        int area = 0;
        // key point is that, from left and right to the highest point. 
        // The height(plus contained water) is increasing.
        while(left < right){
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            // For the smaller side we are sure how much water could it hold
            second = min(leftMax, rightMax);
            if(height[left] < height[right]){
                area += second - height[left];
                left++;
            }else{
                area += second - height[right];
                right--;
            }
        }
        return area;
    }
};
