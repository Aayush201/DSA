// Problem Link : https://www.geeksforgeeks.org/problems/square-root/1

class Solution
{
public:
    long long int floorSqrt(long long int x)
    {
        long long start = 0, end = x;
        long long ans = 1;
        while (start <= end)
        {
            long long mid = start + (end - start) / 2;
            long long val = 1ll * mid * mid;
            if (val == x)
                return mid;
            else if (val < x)
            {
                ans = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
        return ans;
    }
};