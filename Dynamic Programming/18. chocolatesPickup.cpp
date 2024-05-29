// 3d Dp

class Solution
{
public:
    int helper(int i, int jR1, int jR2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        // out of bounds
        if (i >= n || jR1 < 0 || jR1 >= m || jR2 < 0 || jR2 >= m)
            return 0;
        // if we have reached the last row and
        // coordinates of both robots are same then include only once
        if (i == n - 1)
        {
            if (jR1 == jR2)
                return grid[i][jR1];
            else
                return grid[i][jR1] + grid[i][jR2];
        }

        if (dp[i][jR1][jR2] != -1)
            return dp[i][jR1][jR2];

        // now for every single direction for robot1 we have 3 directions for robot2
        // i.e -1 0 1
        int ans = 0;
        for (int dirR1 = -1; dirR1 <= 1; dirR1++)
        {
            for (int dirR2 = -1; dirR2 <= 1; dirR2++)
            {
                // if coordinates of both robots are same then include only once
                if (jR1 == jR2)
                {
                    ans = max(ans, grid[i][jR1] + helper(i + 1, jR1 + dirR1, jR2 + dirR2, n, m, grid, dp));
                }
                // if coordinates of both robots are not same then include both
                else
                {
                    ans = max(ans, grid[i][jR1] + grid[i][jR2] + helper(i + 1, jR1 + dirR1, jR2 + dirR2, n, m, grid, dp));
                }
            }
        }
        return dp[i][jR1][jR2] = ans;
    }
    int solve(int n, int m, vector<vector<int>> &grid)
    {
        // both robots are always getting to next row so we dont have to pass
        // different i coordinates for both the robots
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, -1)));
        return helper(0, 0, m - 1, n, m, grid, dp);
    }
};