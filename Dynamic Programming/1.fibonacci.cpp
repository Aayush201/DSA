class Solution
{
public:
    const int mod = 1e9 + 7;
    long long int dp1[1001], dp2[1001];
    long long int topDown(int n)
    {
        // code here
        if (n <= 1)
            return n;
        if (dp1[n] != 0)
            return dp1[n] % mod;
        return dp1[n] = (topDown(n - 1) % mod + topDown(n - 2) % mod) % mod;
    }
    long long int bottomUp(int n)
    {
        // code here
        dp2[0] = 0;
        dp2[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp2[i] = (dp2[i - 1] % mod + dp2[i - 2] % mod) % mod;
        }
        return dp2[n] % mod;
    }
};