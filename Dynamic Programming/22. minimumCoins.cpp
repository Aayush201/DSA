class Solution
{

public:
    int solve(int M, int V, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (V == 0)
            return 0;
        if (M == 0)
            return 1e9;
        if (dp[M][V] != -1)
            return dp[M][V];
        int pick = 1e9, notpick = 1e9;
        if (coins[M - 1] <= V)
        {
            pick = min(1 + solve(M, V - coins[M - 1], coins, dp), solve(M - 1, V, coins, dp));
        }
        notpick = solve(M - 1, V, coins, dp);
        return dp[M][V] = min(pick, notpick);
    }
    int minCoins(vector<int> &coins, int M, int V)
    {
        // Your code goes here
        vector<vector<int>> dp(M + 1, vector<int>(V + 1, -1));
        int ans = solve(M, V, coins, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};