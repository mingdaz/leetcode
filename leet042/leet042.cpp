class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
    if(right < 2) return 0;
    int leftMax = height[left] , rightMax = height[right], second;
    int area = 0;
    while(left < right){
        leftMax = max(leftMax, height[left]);
        rightMax = max(rightMax, height[right]);
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
