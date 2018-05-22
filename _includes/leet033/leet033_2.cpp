class Solution {
public:
    int search(vector<int>& A, int target) {
        int left = 0, right = A.size()-1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (A[mid] == target)
				return mid;
			if (A[mid] >= A[left]) {
				// [left~mid] is unrotated sorted
				if (A[left] <= target && target < A[mid])
					right = mid-1;
				else
					left = mid + 1;
			} else {
				// [mid~right] is unrotated sorted
				if (A[mid] < target && target <= A[right])
					left = mid + 1;
				else
					right = mid-1;
			}
		}
		return -1;
    }
};