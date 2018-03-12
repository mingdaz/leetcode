class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
        	// Guarantee current dp only contain element in the range [i-k+1,i] 
            if (!dq.empty() && dq.front() < i - k + 1)
                dq.pop_front();
            // Smaller Element has been removed from DQ. The element in the deque is descending order.
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            // Only push to result when we have at least k elements.
            if (i >= k - 1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};