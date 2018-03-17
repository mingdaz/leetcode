class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int n = nums1.size();
        int m = nums2.size();
        int low = 0;
        int high = n;
        
        while(low<=high){
            int partitionX  = (low+high)/2;
            int partitionY  =  (n+m+1)/2 - partitionX;
            int minleftX    = partitionX == 0 ? INT_MIN: nums1[partitionX-1];
            int minrightX   = partitionX == n ? INT_MAX:  nums1[partitionX];
            
            int minleftY    = partitionY == 0 ? INT_MIN: nums2[partitionY-1];
            int minrightY   = partitionY == m ? INT_MAX: nums2[partitionY];
            
            if(minleftX<=minrightY && minleftY<=minrightX){
                if( (n+m)%2 == 0 ){ 
                    //even
 
                    return (double)(max(minleftX,minleftY)+min(minrightX,minrightY))/2;
                }else{
                    //odd
                    return max(minleftX,minleftY);
                }
            }else if(minleftX > minrightY){
                // too far in right in X, move towards left
                high = partitionX-1;
            }else{
                low = partitionX + 1;
            }
        }
    }
};