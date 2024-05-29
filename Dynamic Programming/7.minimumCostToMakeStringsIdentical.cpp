class Solution
{
public:
    int solve(int n, int m, string &X, string &Y, vector<vector<int>> &dp)
    {
        if (n <= 0 || m <= 0)
            return 0;
        if (dp[n][m] != -1)
            return dp[n][m];

        if (X[n - 1] == Y[m - 1])
            return dp[n][m] = 1 + solve(n - 1, m - 1, X, Y, dp);
        return dp[n][m] = max(solve(n - 1, m, X, Y, dp), solve(n, m - 1, X, Y, dp));
    }
    int findMinCost(string X, string Y, int costX, int costY)
    {
        // Your code goes here
        int n = X.length();
        int m = Y.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int len = solve(n, m, X, Y, dp);
        return (n - len) * costX + (m - len) * costY;
    }
};