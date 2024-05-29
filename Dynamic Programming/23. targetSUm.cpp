// this is recursive code and it can be changed to dynamic programming
class Solution
{
public:
    int solve(vector<int> &nums, int index, int val, int target, int n)
    {
        if (index >= n)
        {
            if (target == val)
                return 1;
            return 0;
        }
        return solve(nums, index + 1, val + nums[index], target, n) + solve(nums, index + 1, val - nums[index], target, n);
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        return solve(nums, 0, 0, target, nums.size());
    }
};