class Solution
{
public:
    int solve(vector<vector<int>> &points, int n, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= n || j >= 3)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int pick = 0, notPick = 0;
        if (j == 0)
        {
            pick = points[i][j] + max({solve(points, n, i + 1, j + 1, dp), solve(points, n, i + 1, j + 2, dp)});
        }
        else if (j == 1)
        {
            pick = points[i][j] + max({solve(points, n, i + 1, j - 1, dp), solve(points, n, i + 1, j + 1, dp)});
        }
        else if (j == 2)
        {
            pick = points[i][j] + max({solve(points, n, i + 1, j - 2, dp), solve(points, n, i + 1, j - 1, dp)});
        }
        return dp[i][j] = max(pick, notPick);
    }
    int maximumPoints(vector<vector<int>> &points, int n)
    {
        // Code here
        vector<vector<int>> dp(n + 1, vector<int>(4, -1));
        int ans = 0;
        for (int i = 0; i < 3; i++)
        {
            ans = max(ans, solve(points, n, 0, i, dp));
        }
        return ans;
    }
};