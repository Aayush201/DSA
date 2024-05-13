// Problem Link : https://www.geeksforgeeks.org/problems/smallest-divisor/1

class Solution
{
public:
    int find(vector<int> &nums, int K, int mid)
    {
        long long ans = 0;
        for (auto x : nums)
        {
            ans += ceil((double)x / mid);
        }
        return ans <= K;
    }
    int smallestDivisor(vector<int> &nums, int K)
    {
        int n = nums.size();
        int start = 1, end = 1;
        for (auto x : nums)
            end = max(x, end);
        int ans = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            bool isMidFine = find(nums, K, mid);
            if (isMidFine)
            {
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return ans;
    }
};
