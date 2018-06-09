class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty()) return false;
        int l = 0;
        int r = matrix.size()-1;
        int mid;
        while(l<r){
            mid = l + (r-l)/2;
            if(matrix[mid][0]>target)
                r = mid - 1;
            else if(matrix[mid][0]<target)
                l = mid+1;
            else 
                return true;
        }
        int idx = l;
        if(matrix[idx][0]>target)
            idx--;
        if(idx<0)
            return false;
        l =  0;
        r = matrix[idx].size()-1;
        while(l<r){
            mid = l + (r-l)/2;
            if(matrix[idx][mid]>target)
                r = mid - 1;
            else if(matrix[idx][mid]<target)
                l = mid+1;
            else 
                return true;
        }
        return matrix[idx][l]==target;        
    }
};