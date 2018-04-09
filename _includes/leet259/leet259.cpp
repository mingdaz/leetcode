class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) 
{
    int length = nums.size();
    if (length < 3)
    {
        return 0;
    }

    //key to O(n^2) TC
    //for a sorted array, we can get all valid two sums in linear TC just by comparing left bond and right bond
    sort(nums.begin(), nums.end());

    int result = 0, left = 0, right = length - 1, cur = 0, temp_right = 0, two_sum_target = 0;

    while (nums[left] * 3 < target)
    {
        cur = left + 1;
        temp_right = right;
        two_sum_target = target - nums[left];
        while (cur < right)
        {
            if (nums[cur] + nums[right] >= two_sum_target)
            {
                right--;
            }
            else
            {
                //get number of valid two sums by a simple math but not a loop
                result += right - cur;
                cur++;
            }
        }
        right = temp_right;
        left++;
    }

    return result;
}
};
