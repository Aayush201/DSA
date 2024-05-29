class Solution
{
public:
    int solve(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        if (i >= n || j >= triangle[i].size())
            return 0;
        if (i == n - 1)
            return triangle[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = min(triangle[i][j] + solve(i + 1, j, n, triangle, dp), triangle[i][j] + solve(i + 1, j + 1, n, triangle, dp));
    }
    int minimizeSum(int n, vector<vector<int>> &triangle)
    {
        // Code here
        vector<vector<int>> dp(n + 1, vector<int>(triangle[n - 1].size() + 1, -1));
        return solve(0, 0, n, triangle, dp);
    }
};