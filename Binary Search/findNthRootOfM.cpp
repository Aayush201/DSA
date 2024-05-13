// Problem Link : https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1

class Solution
{
public:
    int power(long long int n, long long int m, long long int mid)
    {
        long long ans = 1;
        for (int i = 1; i <= n; i++)
        {
            ans *= mid;
            if (ans > m)
                return -1;
        }
        if (ans == m)
            return 1;
        return 0;
    }
    int NthRoot(int n, int m)
    {
        int start = 1, end = m;
        while (start <= end)
        {
            long long mid = start + (end - start) / 2;
            int find = power(n, m, mid);
            if (find == 1)
                return mid;
            else if (find == -1)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return -1;
    }
};
