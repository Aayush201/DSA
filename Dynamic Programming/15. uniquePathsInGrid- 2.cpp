class Solution
{
public:
    const int mod = 1e9 + 7;
    int solve(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i == n || j == m || grid[i][j])
            return 0;
        if (i == n - 1 && j == m - 1)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = (solve(i + 1, j, n, m, grid, dp) + solve(i, j + 1, n, m, grid, dp)) % mod;
    }
    int totalWays(int n, int m, vector<vector<int>> &grid)
    {
        // Code here
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(0, 0, n, m, grid, dp);
    }
};