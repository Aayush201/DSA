class Solution
{
public:
    int dp[1001];
    int solve(int *price, int rod_len, int index)
    {
        if (rod_len <= 0 || index == 0)
            return 0;
        if (dp[rod_len] != -1)
            return dp[rod_len];
        int pick = 0;
        if (rod_len - index >= 0)
            pick = price[index - 1] + solve(price, rod_len - index, index);
        int notpick = solve(price, rod_len, index - 1);
        return dp[rod_len] = max(pick, notpick);
    }
    int cutRod(int price[], int n)
    {
        // code here
        memset(dp, -1, sizeof(dp));
        return solve(price, n, n);
    }
};