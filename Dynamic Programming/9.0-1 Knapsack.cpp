class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int solve(int *wt, int *val, int w, int n, vector<vector<int>> &dp)
    {
        if (n == 0 || w <= 0)
        {
            return 0;
        }
        if (dp[n][w] != -1)
            return dp[n][w];
        int pick = 0, notpick = 0;
        if (wt[n - 1] <= w)
        {
            pick = max(val[n - 1] + solve(wt, val, w - wt[n - 1], n - 1, dp), solve(wt, val, w, n - 1, dp));
        }
        notpick = solve(wt, val, w, n - 1, dp);
        return dp[n][w] = max(pick, notpick);
    }
    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        //   vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
        //   return solve(wt,val,W,n,dp);
        vector<int> dp(W + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            for (int j = W; j >= 0; j--)
                if (wt[i - 1] <= j)
                {
                    dp[j] = max(val[i - 1] + dp[j - wt[i - 1]], dp[j]);
                }
        }
        return dp[W];
    }
};