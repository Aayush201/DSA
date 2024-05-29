class Solution
{
public:
    int solve(int n, int w, vector<int> &cost, vector<vector<int>> &dp)
    {
        if (w == 0)
            return 0;
        if (n == 0 || w < 0)
            return 1e9;
        if (dp[n][w] != -1)
            return dp[n][w];
        if (n <= w && cost[n - 1] != -1)
        {
            return dp[n][w] = min(cost[n - 1] + solve(n, w - n, cost, dp), solve(n - 1, w, cost, dp));
        }
        else
        {
            return dp[n][w] = solve(n - 1, w, cost, dp);
        }
    }
    int minimumCost(int n, int w, vector<int> &cost)
    {
        // code here
        // vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
        // int ans = solve(n,w,cost,dp);
        // return ans >= 1e9 ? -1 : ans;

        // tabulation
        vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= w; j++)
            {
                if (j == 0)
                    dp[i][j] = 0;
                else if (i == 0)
                    dp[i][j] = 1e9;
                else
                {
                    if (i <= j && cost[i - 1] != -1)
                    {
                        dp[i][j] = min(cost[i - 1] + dp[i][j - i], dp[i - 1][j]);
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
        }
        return dp[n][w] >= 1e9 ? -1 : dp[n][w];
    }
};