class Solution {
public:
    int partition(vector<int>& nums, int l, int r) {
        int mid = (r - l)/2 + l;
        swap(nums[mid], nums[r]);
        int pivot = nums[r];
        int i = l;
        for (int k = l; k < r; k++) {
            if (nums[k] > pivot) {
                swap(nums[k], nums[i++]);
            }
        }
        swap(nums[i], nums[r]);
        return i;
        
    }
    int findKthLargest(vector<int>& nums, int k) {
        if (!nums.size()) return -1;
        k--;
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int idx = partition(nums, i, j);
            if (idx == k)
                return nums[idx];
            else if (idx < k) {
                i = idx + 1;
            }
            else {
                j = idx;
            }
        }
        return nums[i];
        
    }
};